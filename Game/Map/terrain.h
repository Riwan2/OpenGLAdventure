#ifndef TERRAIN_H
#define TERRAIN_H

#include <glm/glm.hpp>
#include "../headers/vaoobject.h"
#include "../Basic/util.h"

#include "map.h"

class Terrain : public Map
{
public:
    Terrain(const float& size, ShaderLoader& shaderLoader, int textureId);
    ~Terrain();
    
    void Render();
private:
    glm::mat4 m_model;
    glm::vec3 m_color;
    
    GLuint m_textureId;
    float* m_heightMap;
    
    void GenerateHeigtMap();
};

#endif // TERRAIN_H
