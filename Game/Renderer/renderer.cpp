#include "renderer.h"

bool operator==(const Model& m1, const Model& m2) {
        return (m1.GetVAO() == m2.GetVAO() && m1.GetVBO() == m2.GetVBO() && m1.GetEBO() == m2.GetEBO() &&
        m1.GetTexture().getId() == m2.GetTexture().getId() && m1.GetDrawCall() == m2.GetDrawCall());
}

enum eEntity {
     tree
};

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
    m_listEntity.clear();
    m_entities.clear();
    m_listModel.clear();
    delete m_basicShader;
}

void Renderer::Load(const glm::mat4& projection, Terrain* terrain)
{
    m_basicShader = new ShaderLoader();
    m_basicShader->Load("basicShaderInstanced");
    
    //Entity
    SetUniform(projection);
    LoadEntity(terrain);
}

void Renderer::LoadEntity(Terrain* terrain)
{
    //Set Texture
    Texture* treeTexture = new Texture("tree", 0.0, 64);
    //Set Model
    int nbEntity = 1;
    m_listModel.push_back(new Model(new ModelLoader("tree", true), treeTexture));
    //Delete Texture
    delete treeTexture;
    //Set Entities
    for (int i = 0; i < nbEntity; i++) {
        m_listEntity.push_back(std::vector<Entity*>());
    }
    glm::vec3 randomPos;
    //Tree
    for (int i = 0; i < 50; i++) {
        randomPos = glm::vec3(Util::getInt(600)-300, 0, Util::getInt(600)-300);
        for (int a = 0; a < 50; a++) {
            float posX, posZ;
            do {
                posX = randomPos.x + float(Util::getInt(300)-150) / 5;
                posZ = randomPos.z + float(Util::getInt(300)-150) / 5;
            } while(terrain->GetMapHeight(posX, posZ) < -5.5);

            m_listEntity[eEntity::tree].push_back(new Entity(m_listModel[eEntity::tree],
                *m_basicShader, posX, terrain->GetMapHeight(posX, posZ), posZ, 1.2));
        }
    }
}

void Renderer::Render(const float& deltaTime, const Camera& camera, const std::vector<Terrain*>& listTerrain, Light* light)
{
    UpdateUniform(camera, light);    
    
    //light->Render(camera.GetProjection(), camera.GetView());
    
    //Terrain
    EnableCulling();
    for (int i = 0; i < listTerrain.size(); i++) {
        listTerrain[i]->Render(&camera, light);
    }
    //Tree
    for (int i = 0; i < m_listEntity[eEntity::tree].size(); i++) {
        Entity* tree = m_listEntity[eEntity::tree][i];
        ProcessEntity(tree);
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
        if (p->first->isInstanced()) 
        {
            glm::mat4* modelMatrices = new glm::mat4[p->second.size()];
            for (int i = 0; i < p->second.size(); i++) {
                modelMatrices[i] = p->second[i]->GetModelMatrix();
            }

            p->second[0]->Update();
            p->first->Render(modelMatrices, p->second.size());
            delete[] modelMatrices;
        }
         else 
        {
            for (int i = 0; i < p->second.size(); i++) {
                p->second[i]->Update();
                p->first->Render();
            }
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

void Renderer::UpdateUniform(const Camera& camera, Light* light)
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_UBOMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(camera.GetView()));
    glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), sizeof(glm::vec4), glm::value_ptr(light->getPosition()));
    glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4) + sizeof(glm::vec4), sizeof(glm::vec4), glm::value_ptr(light->getColor()));
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