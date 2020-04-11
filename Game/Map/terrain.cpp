#include "terrain.h"
#include "../Basic/parameters.h"

Terrain::Terrain(const float& posX, const float& posZ, const float& size, ShaderLoader& shaderLoader, Texture* texture) 
{
    //GenerateHeigtMap();
    m_shader = new Shader(shaderLoader);
    m_texture = new Texture(*texture);
    
    m_map = new Map(posX, posZ, size);
    m_map->Initialize(m_heightMap);
    
    m_model = glm::mat4(1.0f);
    m_color = glm::vec3(0.1f, 0.5f, 0.4f);
}

Terrain::~Terrain()
{
    //delete m_heightMap;
    glDeleteTextures(1, &m_texture->getId());
    delete m_texture;
    delete m_map;
    delete m_shader;
}

void Terrain::GenerateHeigtMap()
{
//     m_heightMap = new float[GetNumVertices()];
//     
//     for (int i = 0; i < GetNumVertices(); i++) {
//         m_heightMap[i] = 0.0f;//float(Util::getInt(10)) / 150;
//     }
}

void Terrain::Render(const Camera* camera, const Light* light)
{   
    m_shader->Use();
    m_shader->SetMat4("projection", camera->GetProjection());
    m_shader->SetMat4("view", camera->GetView());
    m_shader->SetMat4("model", m_model);
    m_shader->SetVec3("lightPos", light->getPosition());
    m_shader->SetVec3("lightColor", light->getColor());
    m_shader->SetVec3("skyColor", parameters::skyColor);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_texture->getId());
    m_map->BasicRendering();
    glDisable(GL_TEXTURE_2D);
}

