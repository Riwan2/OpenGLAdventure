#ifndef TERRAIN_H
#define TERRAIN_H

#include "../Loader/texture.h"
#include "../Basic/util.h"
#include "../Basic/camera.h"
#include "../Basic/light.h"
#include "map.h"

class Terrain : public Map
{
public:
    Terrain(const float& posX, const float& posZ, const float& size, ShaderLoader& shaderLoader, Texture* grass, Texture* path,
Texture* blendMap);
    ~Terrain();
    
    void Render(const Camera* camera, const Light* light);
private:
    glm::mat4 m_model;
    glm::vec3 m_color;
    
    Texture* m_grass;
    Texture* m_path;    
    Texture* m_blendMap;
    Shader* m_shader;
    
    void LoadHeightMap();
};

#endif // TERRAIN_H
