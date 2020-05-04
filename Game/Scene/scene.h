#ifndef SCENE_H
#define SCENE_H

#include "../Renderer/renderer.h"
#include "../Entity/player.h"
#include "../Map/water.h"
#include "../Map/skybox.h"
#include "../Interaction/mousepicker.h"
#include "../Model/simpleobject.h"

class Scene
{
public:
	Scene();
	~Scene();

	void Initialize();
	void Update(const float& deltaTime);
private:
	MousePicker* m_mousePicker;
	Skybox* m_skybox;
	Water* m_water;
	Renderer* m_renderer;
	Camera* m_camera;
    Player* m_player;
    std::vector<light::PointLight*> m_listPointLight;
    std::vector<Terrain*> m_listTerrain;
};

#endif //SCENE_H