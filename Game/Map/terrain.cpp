#include "terrain.h"

Terrain::Terrain(const float& size, ShaderLoader& shaderLoader, int textureId) 
: Map { size, shaderLoader, textureId }
{
    GenerateHeigtMap();
    Initialize(m_heightMap);
    
    m_model = glm::mat4(1.0f);
    m_color = glm::vec3(0.1f, 0.5f, 0.4f);
}

Terrain::~Terrain()
{
    delete m_heightMap;
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
    
    Map::BasicRendering();
}

