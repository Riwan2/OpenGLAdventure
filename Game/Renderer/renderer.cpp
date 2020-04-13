#include "renderer.h"

bool operator==(const Model& m1, const Model& m2) {
        return (m1.GetVAO() == m2.GetVAO() && m1.GetVBO() == m2.GetVBO() && m1.GetEBO() == m2.GetEBO() &&
        m1.GetTexture().getId() == m2.GetTexture().getId() && m1.GetDrawCall() == m2.GetDrawCall());
}

enum eEntity {
     grass, tree
};

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
    m_listEntity.clear();
    m_listModel.clear();
    m_listTerrain.clear();
    m_entities.clear();
    delete m_light;
    delete m_basicShader;
}

void Renderer::Load(const glm::mat4& projection)
{
    ShaderLoader* lightShader = new ShaderLoader();
    lightShader->Load("lightShader");
    ShaderLoader* terrainShader = new ShaderLoader();
    terrainShader->Load("terrainShader");
    m_basicShader = new ShaderLoader();
    m_basicShader->Load("basicShader");

    //Light
    glm::vec3 lightColor = glm::vec3(1.0, 1.0, 1.0f); //0.9, 0.8, 0.7
    m_light = new Light(lightColor, *lightShader);
    m_light->Move(glm::vec3(-10, 10, 10.0));
    delete lightShader;
    
    //Terrain
    Texture* grass = new Texture("green", 0.0, 64);
    m_listTerrain.push_back(new Terrain(-0.5, -0.5, 500, *terrainShader, grass));
    delete grass;
    
    SetUniform(projection);
    LoadEntity();
}

void Renderer::LoadEntity()
{
    //Set Texture
    Texture* grassTexture = new Texture("grassobject", 0.0, 64, true);
    Texture* treeTexture = new Texture("tree", 0.0, 64);
    //Set Model
    int nbEntity = 2;
    m_listModel.push_back(new Model(new ModelLoader("grass"), grassTexture, true));
    m_listModel.push_back(new Model(new ModelLoader("tree"), treeTexture));
    //Delete Texture
    delete grassTexture;
    delete treeTexture;
    //Set Entities
    for (int i = 0; i < nbEntity; i++) {
        m_listEntity.push_back(std::vector<Entity*>());
    }
    glm::vec3 randomPos;
    //grass
    //Tree
    for (int i = 0; i < 10; i++) {
        randomPos = glm::vec3(Util::getInt(100)-50, 0, Util::getInt(100)-50);
        for (int a = 0; a < 20; a++) {
            m_listEntity[eEntity::tree].push_back(new Entity(*m_listModel[eEntity::tree], *m_basicShader, randomPos.x + float(Util::getInt(300)-150) / 10, randomPos.y,
            randomPos.z + float(Util::getInt(300)-150) / 10));
            
            for (int b = 0; b < 2; b++) {
                m_listEntity[eEntity::grass].push_back(new Entity(*m_listModel[eEntity::grass], *m_basicShader, randomPos.x + (float)(Util::getInt(300)-150) / 10, randomPos.y, randomPos.z + (float)(Util::getInt(300)-150) / 10, true));
            }
        }
    }
    
    std::cout << m_listEntity[eEntity::grass].size() << std::endl;
}

void Renderer::Render(const Camera& camera)
{
    UpdateUniform(camera);
    
    //m_light->Render(camera.GetProjection(), camera.GetView());
    
    for (int i = 0; i < m_listTerrain.size(); i++) {
        m_listTerrain[i]->Render(&camera, m_light);
    }
    
    //Tree
    for (int i = 0; i < m_listEntity[eEntity::tree].size(); i++) {
        Entity* tree = m_listEntity[eEntity::tree][i];
        ProcessEntity(tree);
    }
    //grass
    for (int i = 0; i < m_listEntity[eEntity::grass].size(); i++) {
        Entity* grass = m_listEntity[eEntity::grass][i];
        grass->SetRotation(0, 0, 180 - camera.GetAngleAround() + 90);
        ProcessEntity(grass);
    }
    
    RenderEntity();
}

void Renderer::ProcessEntity(Entity*& entity)
{
    Model* model = &entity->GetModel();
    std::unordered_map<Model*, std::vector<Entity*>, ModelHashFunction>:: iterator batch;
    batch = m_entities.find(model);
    
    if (batch != m_entities.end()) {
        batch->second.push_back(entity);
    } else {
        std::vector<Entity*> newBatch;
        newBatch.push_back(entity);
        m_entities.emplace(model, newBatch);
    }
}

void Renderer::RenderEntity()
{
    std::unordered_map<Model*, std::vector<Entity*>, ModelHashFunction>:: iterator p;
    for (p = m_entities.begin(); p != m_entities.end(); p++) {
        if (p->first->GetTransparency()) DisableCulling();
        else EnableCulling();
        p->first->Bind();
        for (int i = 0; i < p->second.size(); i++) {
            p->second[i]->Update();
            p->first->Render();
        }
        p->first->Unbind();
    }
    m_entities.clear();
}

void Renderer::SetUniform(const glm::mat4& projection)
{
    GLuint uniformBlockIndexBasicShader = glGetUniformBlockIndex(m_basicShader->getShaderProgramId(), "Matrices");
    glUniformBlockBinding(m_basicShader->getShaderProgramId(), uniformBlockIndexBasicShader, 0);
    
    glGenBuffers(1, &m_UBOMatrices);

    glBindBuffer(GL_UNIFORM_BUFFER, m_UBOMatrices);
    glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4) + 2 * sizeof(glm::vec4), NULL, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    glBindBufferRange(GL_UNIFORM_BUFFER, 0, m_UBOMatrices, 0, 2 * sizeof(glm::mat4) + 2 * sizeof(glm::vec4));

    glBindBuffer(GL_UNIFORM_BUFFER, m_UBOMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projection));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void Renderer::UpdateUniform(const Camera& camera)
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_UBOMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(camera.GetView()));
    glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), sizeof(glm::vec4), glm::value_ptr(m_light->getPosition()));
    glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4) + sizeof(glm::vec4), sizeof(glm::vec4), glm::value_ptr(m_light->getColor()));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void Renderer::EnableCulling()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void Renderer::DisableCulling()
{
    glDisable(GL_CULL_FACE);
}
