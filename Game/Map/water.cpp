#include "water.h"

Water::Water(const float& size, ShaderLoader& shaderLoader) 
: Map { size, shaderLoader }
{
    FlatHeightMap();
    Initialize(m_heightMap);
    
    m_model = glm::mat4(1.0f);
    m_color = glm::vec3(0.2f, 0.3f, 1.0f);
    m_model = glm::translate(m_model, glm::vec3(-40, 0, -30));
    m_time = 0;
}

Water::~Water()
{
    delete m_heightMap;
}

void Water::Render(const glm::mat4& projection, const glm::mat4& view, const glm::vec3& lightColor, const glm::vec3& lightPos)
{
    m_time += 0.01f;
    m_shader->Use();
    
    m_shader->SetMat4("projection", projection);
    m_shader->SetMat4("view", view);
    m_shader->SetMat4("model", m_model);
    m_shader->SetVec3("myColor", m_color);
    m_shader->SetVec3("lightColor", lightColor);
    m_shader->SetVec3("lightPos", lightPos);
    m_shader->SetFloat("time", m_time);
    
    Map::BasicRendering();
}

void Water::FlatHeightMap()
{
    m_heightMap = new float[GetNumVertices()];
    for (int i = 0; i < GetNumVertices(); i++) {
        m_heightMap[i] = 0.0f;
    }
}

