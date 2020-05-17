#ifndef SCENE_H
#define SCENE_H

#include "../Renderer/renderer.h"
#include "../Map/water.h"
#include "../Map/skybox.h"
#include "../Interaction/mousepicker.h"
#include "../Model/staticobject.h"
#include "../DataStruct/quadtree.h"
#include "../Object/player.h"

class Scene
{
public:
	Scene();
	~Scene();

	void Initialize();
	void Update(const float& deltaTime);
private:
	data::QuadTree* m_quadTree;
	std::vector<data::Node> m_inRange;

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