#include "terrain.h"
#include "../Basic/parameters.h"

Terrain::Terrain(const float& posX, const float& posZ, const float& size, ShaderLoader& shaderLoader, Texture* grass, Texture* path,
Texture* blendMap) 
{
    //GenerateHeigtMap();
    m_shader = new Shader(shaderLoader);
    m_grass = new Texture(*grass);
    m_path = new Texture(*path);
    m_blendMap = new Texture(*blendMap);
    
    m_map = new Map(posX, posZ, size);
    m_map->Initialize(m_heightMap);
    
    m_model = glm::mat4(1.0f);
    m_color = glm::vec3(0.1f, 0.5f, 0.4f);
}

Terrain::~Terrain()
{
    //delete m_heightMap;
    glDeleteTextures(1, &m_grass->getId());
    glDeleteTextures(1, &m_path->getId());
    glDeleteTextures(1, &m_blendMap->getId());

    delete m_grass;
    delete m_path;
    delete m_blendMap;

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
    m_shader->SetInt("grass", 0);
    m_shader->SetInt("path", 1);
    m_shader->SetInt("blendMap", 2);
    
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_grass->getId());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_path->getId());
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, m_blendMap->getId());

    m_map->BasicRendering();
    glDisable(GL_TEXTURE_2D);
}

