#ifndef WATER_H
#define WATER_H

#include "map.h"

class Water : public Map
{
public:
    Water(const float& posX, const float& posZ, const float& size, ShaderLoader& shaderLoader);
    ~Water();
    
    void Render(const glm::mat4& projection, const glm::mat4& view, const glm::vec3& lightColor, const glm::vec3& lightPos);
private:
    glm::mat4 m_model;
    glm::vec3 m_color;
    float m_time;
    
    float* m_heightMap;
    Shader* m_shader;
    
    void FlatHeightMap();
};

#endif // WATER_H
