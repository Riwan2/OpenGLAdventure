#ifndef WATER_H
#define WATER_H

#include "map.h"

class Water : public Map
{
public:
    Water(const float& posX, const float& posZ, const float& size, const shld::ShaderObj& shaderObj, txtl::Texture2d* texture, txtl::Texture2d* displacementMap);
    ~Water();
    
    void Render(const Camera* camera);
private:
    glm::mat4 m_model;
    float m_time;
    
    txtl::Texture2d* m_texture;
    txtl::Texture2d* m_displacementMap;    
    Shader* m_shader;
    
    void FlatHeightMap();
};

#endif // WATER_H
