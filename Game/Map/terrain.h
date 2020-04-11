#ifndef TERRAIN_H
#define TERRAIN_H

#include <glm/glm.hpp>
#include "../Loader/texture.h"
#include "../Basic/util.h"
#include "../Map/map.h"
#include "../Basic/camera.h"
#include "../headers/light.h"

#include "map.h"

class Terrain
{
public:
    Terrain(const float& posX, const float& posZ, const float& size, ShaderLoader& shaderLoader, Texture* texture);
    ~Terrain();
    
    void Render(const Camera* camera, const Light* light);
private:
    glm::mat4 m_model;
    glm::vec3 m_color;
    
    Texture* m_texture;
    Map* m_map;
    Shader* m_shader;
    float* m_heightMap;
    
    void GenerateHeigtMap();
};

#endif // TERRAIN_H
