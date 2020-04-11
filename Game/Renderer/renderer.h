#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <iostream>
#include <string>

#include "../Loader/texture.h"
#include "../Model/shader.h"
#include "../Model/model.h"
#include "../Entity/entity.h"

#include "../headers/light.h"
#include "../Basic/camera.h"
#include "../Basic/util.h"

#include "../Map/terrain.h"

#include <unordered_map>
#include <map>
#include <vector>

class Renderer
{
public:
    Renderer();
    ~Renderer();
    
    void Load(const glm::mat4& projection);
    void Render(const Camera& camera);
    
private:
    std::unordered_map<Model*, std::vector<Entity*>, ModelHashFunction> m_entities;
    ShaderLoader* m_basicShader;
    GLuint m_UBOMatrices;
    Light* m_light;
    
    std::vector<Model*> m_listModel;
    std::vector<std::vector<Entity*>> m_listEntity;
    std::vector<Terrain*> m_listTerrain;
    
    void LoadEntity();
    void SetUniform(const glm::mat4& projection);
    void UpdateUniform(const Camera& camera);
    void ProcessEntity(Entity*& entity);
    void RenderEntity();
    void EnableCulling();
    void DisableCulling();
};

#endif // RENDERER_H
