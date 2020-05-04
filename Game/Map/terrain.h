#ifndef TERRAIN_H
#define TERRAIN_H

#include "../Basic/util.h"
#include "../Basic/light.h"
#include "map.h"

class Terrain : public Map
{
public:
    Terrain(const float& posX, const float& posZ, const float& size, const shld::ShaderObj& shaderObj, txtl::Texture2d* grass, txtl::Texture2d* path, txtl::Texture2d* blendMap);
    ~Terrain();
    
    void Render(const Camera* camera, const std::vector<light::PointLight*>& listPointLight);
private:
    glm::mat4 m_model;
    glm::vec3 m_color;
    
    txtl::Texture2d* m_grass;
    txtl::Texture2d* m_path;    
    txtl::Texture2d* m_blendMap;
    Shader* m_shader;
    
    void LoadHeightMap();
};

#endif // TERRAIN_H
