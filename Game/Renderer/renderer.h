#ifndef RENDERER_H
#define RENDERER_H

#include "../Entity/entity.h"
#include "../Map/terrain.h"
#include "../DataStruct/quadtree.h"
#include <unordered_map>
#include <map>

class Renderer
{
public:
    Renderer();
    ~Renderer();
    
    void Load(const glm::mat4& projection, Terrain* terrain);
    void Render(const float& deltaTime, const Camera& camera, const std::vector<Terrain*>& listTerrain, const std::vector<light::PointLight*>& listPointLight, data::QuadTree& quadTree);
    
private:
    std::unordered_map<Model*, std::vector<Entity*>, ModelHashFunction> m_entities;
    shld::ShaderObj* m_basicShader;
    GLuint m_UBOMatrices;

    std::vector<Model*> m_listModel;
    std::vector<std::vector<Entity*>> m_listEntity;
    
    void LoadEntity(Terrain* terrain);
    void SetUniform(const glm::mat4& projection);
    void UpdateUniform(const Camera& camera, const std::vector<light::PointLight*>& listPointLight);
    void ProcessEntity(Entity*& entity, data::QuadTree& quadTree);
    void RenderEntity();
    void EnableCulling();
    void DisableCulling();
};

#endif // RENDERER_H
