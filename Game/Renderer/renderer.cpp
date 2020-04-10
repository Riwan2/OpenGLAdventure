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
    for (int i = 0; i < m_listModel.size(); i++) {
        delete m_listModel[i];
    }
    for (int i = 0; i < m_listEntity.size(); i++) {
        for (int a = 0; a < m_listEntity[i].size(); a++) {
            delete m_listEntity[i][a];
        }
    }
    m_entities.clear();
    delete m_light;
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
    delete lightShader;

    SetUniform(basicShader, projection);
    LoadEntity(basicShader);
    delete basicShader;
}

void Renderer::LoadEntity(ShaderLoader*& basicShader)
{
    //Set Texture
    Texture* dragonTexture = new Texture("white");
    Texture* stallTexture = new Texture("stall");
    //Set Model
    int nbModel = 2;
    enum eModel {
        dragon, stall
    };
    m_listModel.push_back(new Model(new ModelLoader("dragon"), dragonTexture->getId()));
    m_listModel.push_back(new Model(new ModelLoader("stall"), stallTexture->getId()));
    //Delete Texture
    delete dragonTexture;
    delete stallTexture;
    //Set Entities
    for (int i = 0; i < nbModel; i++) {
        m_listEntity.push_back(std::vector<Entity*>());
    }
    glm::vec3 randomPos;
    //Dragon
    for (int i = 0; i < 10; i++) {
        randomPos = glm::vec3(Util::getInt(70)-35, Util::getInt(10)-5, Util::getInt(70)-35);
        m_listEntity[eModel::dragon].push_back(new Entity(*m_listModel[eModel::dragon], *basicShader, randomPos.x, randomPos.y, randomPos.z));
    }
    //Stall
    for (int i = 0; i < 100; i++) {
        randomPos = glm::vec3(Util::getInt(70)-35, Util::getInt(10)-5, Util::getInt(70)-35);
        m_listEntity[eModel::stall].push_back(new Entity(*m_listModel[eModel::stall], *basicShader, randomPos.x, randomPos.y, randomPos.z));
    }
    //Set Entities Model
    for (int i = 0; i < nbModel; i++) {
        m_entities.emplace(*m_listModel[i], m_listEntity[i]);
    }
}

void Renderer::Render(const glm::mat4& projection, Camera& camera)
{
    UpdateUniform(camera);
    m_light->Render(projection, camera.getView());
    RenderEntity();
}

void Renderer::RenderEntity()
{
    std::unordered_map<Model, std::vector<Entity*>, ModelHashFunction>:: iterator p;
    for (p = m_entities.begin(); p != m_entities.end(); p++) {             
        p->first.Bind();
        for (int i = 0; i < p->second.size(); i++) {
            p->second[i]->Update();
            p->second[i]->Rotate(0, 0, 0.25);
            p->first.Render();
        }
        p->first.Unbind();
    }
}

void Renderer::SetUniform(ShaderLoader*& basicShader, const glm::mat4& projection)
{
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
}

void Renderer::UpdateUniform(Camera& camera)
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_UBOMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(camera.getView()));
    glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), sizeof(glm::vec4), glm::value_ptr(m_light->getPosition()));
    glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4) + sizeof(glm::vec4), sizeof(glm::vec4), glm::value_ptr(m_light->getColor()));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}