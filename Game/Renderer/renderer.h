#ifndef RENDERER_H
#define RENDERER_H

#include "../Entity/entity.h"
#include "../Map/terrain.h"
#include <unordered_map>
#include <map>

class Renderer
{
public:
    Renderer();
    ~Renderer();
    
    void Load(const glm::mat4& projection, Terrain* terrain);
    void Render(const float& deltaTime, const Camera& camera, const std::vector<Terrain*>& listTerrain, Light* light);
    
private:
    std::unordered_map<Model*, std::vector<Entity*>, ModelHashFunction> m_entities;
    ShaderLoader* m_basicShader;
    GLuint m_UBOMatrices;

    std::vector<Model*> m_listModel;
    std::vector<std::vector<Entity*>> m_listEntity;
    
    void LoadEntity(Terrain* terrain);
    void SetUniform(const glm::mat4& projection);
    void UpdateUniform(const Camera& camera, Light* light);
    void ProcessEntity(Entity*& entity);
    void RenderEntity();
    void EnableCulling();
    void DisableCulling();
};

#endif // RENDERER_H
