#ifndef TERRAIN_H
#define TERRAIN_H

#include <glm/glm.hpp>
#include "../Loader/shader.h"
#include "../headers/vaoobject.h"
#include "../Basic/util.h"

#include "map.h"

class Terrain : public Map
{
public:
    Terrain(const int& width, const int& height, const float& vertexSize, ShaderLoader& shaderLoader);
    ~Terrain();
    
    void Render(const glm::mat4& projection, const glm::mat4& view, const glm::vec3& lightColor, const glm::vec3& lightPos);
private:
    glm::mat4 m_model;
    glm::vec3 m_color;
    
    float* m_heightMap;
    Shader* m_shader;
    
    void GenerateHeigtMap();
};

#endif // TERRAIN_H
