#ifndef WATER_H
#define WATER_H

#include "map.h"

class Water : public Map
{
public:
    Water(const float& posX, const float& posZ, const float& size, ShaderLoader& shaderLoader, Texture* texture, Texture* displacementMap);
    ~Water();
    
    void Render(const Camera* camera);
private:
    glm::mat4 m_model;
    float m_time;
    
    Texture* m_texture;
    Texture* m_displacementMap;    
    Shader* m_shader;
    
    void FlatHeightMap();
};

#endif // WATER_H
