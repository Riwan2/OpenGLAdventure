#ifndef WATER_H
#define WATER_H

#include <glm/glm.hpp>
#include "../headers/vaoobject.h"
#include "map.h"

class Water : public Map
{
public:
    Water(const int& width, const int& height, const float& vertexSize, ShaderLoader& shaderLoader);
    ~Water();
    
    void Render(const glm::mat4& projection, const glm::mat4& view, const glm::vec3& lightColor, const glm::vec3& lightPos);
private:
    glm::mat4 m_model;
    glm::vec3 m_color;
    float m_time;
    
    float* m_heightMap;
    
    void FlatHeightMap();
};

#endif // WATER_H