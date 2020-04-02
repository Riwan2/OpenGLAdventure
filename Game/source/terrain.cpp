#include "../headers/terrain.h"
#include "../headers/util.h"

Terrain::Terrain(const int& width, const int& height, const float& vertexSize) 
: Map { width, height, vertexSize }
{
    GenerateHeigtMap();
    Initialize(m_heightMap);
    
    m_shader = new Shader("../Shader/terrainShader");
    
    m_model = glm::mat4(1.0f);
    m_color = glm::vec3(0.1f, 0.5f, 0.4f);
}

Terrain::~Terrain()
{
    delete m_heightMap;
    delete m_shader;
}

void Terrain::GenerateHeigtMap()
{
    m_heightMap = new float[GetNumVertices()];
    
    for (int i = 0; i < GetNumVertices(); i++) {
        m_heightMap[i] = 0.0f;//float(Util::getInt(10)) / 150;
    }
}

void Terrain::Render(const glm::mat4& projection, const glm::mat4& view, const glm::vec3& lightColor, const glm::vec3& lightPos)
{   
    m_shader->Use();
    
    m_shader->SetMat4("projection", projection);
    m_shader->SetMat4("view", view);
    m_shader->SetMat4("model", m_model);
    m_shader->SetVec3("myColor", m_color);
    m_shader->SetVec3("lightColor", lightColor);
    m_shader->SetVec3("lightPos", lightPos);
    
    Map::BasicRendering();
}

