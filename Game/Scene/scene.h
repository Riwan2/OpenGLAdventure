#ifndef SCENE_H
#define SCENE_H

#include "../Renderer/renderer.h"
#include "../Entity/player.h"

class Scene
{
public:
	Scene();
	~Scene();

	void Initialize();
	void Update(const float& deltaTime);
private:
	Renderer* m_renderer;
	Camera* m_camera;
    Player* m_player;
    Light* m_light;
    std::vector<Terrain*> m_listTerrain;
};

#endif //SCENE_H