#include "renderer.h"

bool operator==(const Model& m1, const Model& m2) {
        return (m1.GetVAO() == m2.GetVAO() && m1.GetVBO() == m2.GetVBO() && m1.GetEBO() == m2.GetEBO() &&
        m1.GetTextureID() == m2.GetTextureID() && m1.GetDrawCall() == m2.GetDrawCall());
}

Renderer::Renderer()
{
    
}

Renderer::~Renderer()
{
    for (int i = 0; i < listModel.size(); i++) {
        delete listModel[i];
    }
    delete m_light;
    delete m_entities;
}

void Renderer::Load(const glm::mat4& projection)
{
     ShaderLoader* lightShader = new ShaderLoader();
     lightShader->Load("lightShader");
     
     ShaderLoader* basicShader = new ShaderLoader();
     basicShader->Load("basicShader");
       
     glm::vec3 lightColor = glm::vec3(1.0, 1.0, 1.0); //0.9, 0.8, 0.7
     m_light = new Light(lightColor, *lightShader);
     m_light->Move(glm::vec3(-10, 10, 10.0));  
     
    GLuint uniformBlockIndexBasicShader = glGetUniformBlockIndex(basicShader->getShaderProgramId(), "Matrices");
    glUniformBlockBinding(basicShader->getShaderProgramId(), uniformBlockIndexBasicShader, 0);
    
    glGenBuffers(1, &m_UBOMatrices);
    
    glBindBuffer(GL_UNIFORM_BUFFER, m_UBOMatrices);
    glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4) + 2 * sizeof(glm::vec4), NULL, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    glBindBufferRange(GL_UNIFORM_BUFFER, 0, m_UBOMatrices, 0, 2 * sizeof(glm::mat4) + 2 * sizeof(glm::vec4));
    
    glBindBuffer(GL_UNIFORM_BUFFER, m_UBOMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projection));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    Texture* dragonTexture = new Texture("white");
    Texture* stallTexture = new Texture("stall");
    
    enum eModel {
        dragon, stall
    };
    
    listModel.push_back(new Model(new ModelLoader("dragon"), dragonTexture->getId()));
    listModel.push_back(new Model(new ModelLoader("stall"), stallTexture->getId()));
    
    delete dragonTexture;
    delete stallTexture;
    
    int nbDragons = 100;
    std::vector<Entity*> dragonVector;
    std::vector<Entity*> stallVector;
    
    for (int i = 0; i < nbDragons; i++) {
        glm::vec3 randomPos = glm::vec3(Util::getInt(70)-35, Util::getInt(10)-5, Util::getInt(70)-35);
        if (i < 10)
           dragonVector.push_back(new Entity(*listModel[eModel::dragon], *basicShader, randomPos.x, randomPos.y, randomPos.z));
        stallVector.push_back(new Entity(*listModel[eModel::stall], *basicShader, randomPos.x, randomPos.y, randomPos.z));
    }
    
    m_entities = new std::unordered_map<Model, std::vector<Entity*>, ModelHashFunction>();
    m_entities->emplace(*listModel[0], dragonVector);
    m_entities->emplace(*listModel[1], stallVector);
}

void Renderer::Render(const glm::mat4& projection, Camera& camera)
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_UBOMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(camera.getView()));
    glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), sizeof(glm::vec4), glm::value_ptr(m_light->getPosition()));
    glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4) + sizeof(glm::vec4), sizeof(glm::vec4), glm::value_ptr(m_light->getColor()));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    m_light->Render(projection, camera.getView());
    
    std::unordered_map<Model, std::vector<Entity*>, ModelHashFunction>:: iterator p;
    for (p = m_entities->begin(); p != m_entities->end(); p++) {             
        p->first.Bind();
        for (int i = 0; i < p->second.size(); i++) {
            p->second[i]->Update();
            p->second[i]->Rotate(0, 0, 0.25);
            p->first.Render();
        }
        p->first.Unbind();
    }
}
