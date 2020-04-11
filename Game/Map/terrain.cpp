#include "terrain.h"

Terrain::Terrain(const float& size, ShaderLoader& shaderLoader, int textureId) 
: Map { size, shaderLoader }
{
    GenerateHeigtMap();
    Initialize(m_heightMap);
    
    m_textureId = textureId;
    
    m_model = glm::mat4(1.0f);
    m_color = glm::vec3(0.1f, 0.5f, 0.4f);
}

Terrain::~Terrain()
{
    delete m_heightMap;
    glDeleteTextures(1, &m_textureId);
}

void Terrain::GenerateHeigtMap()
{
    m_heightMap = new float[GetNumVertices()];
    
    for (int i = 0; i < GetNumVertices(); i++) {
        m_heightMap[i] = 0.0f;//float(Util::getInt(10)) / 150;
    }
}

void Terrain::Render()
{   
    m_shader->Use();
    m_shader->SetMat4("model", m_model);
    m_shader->SetVec3("myColor", m_color);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_textureId);
    Map::BasicRendering();
    glDisable(GL_TEXTURE_2D);
}

