#include "scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{
	delete m_camera;
	delete m_renderer;
	delete m_player;
	delete m_light;
	m_listTerrain.clear();
}

void Scene::Initialize()
{
	//Camera
	m_camera = new Camera(30);

    //Terrain
    ShaderLoader* terrainShader = new ShaderLoader();
    terrainShader->Load("terrainShader");
    Texture* grass = new Texture("grass", 0.0, 64);
    Texture* path = new Texture("path", 0.0, 64);
    Texture* blendMap = new Texture("blendmap", 0.0, 64);
    m_listTerrain.push_back(new Terrain(-0.5, -0.5, 800, *terrainShader, grass, path, blendMap));
    delete blendMap;
    delete path;
    delete grass;
    delete terrainShader;

    //Entity
    m_renderer = new Renderer();
    m_renderer->Load(m_camera->GetProjection(), m_listTerrain[0]);

    //Light
    ShaderLoader* lightShader = new ShaderLoader();
    lightShader->Load("lightShader");
    glm::vec3 lightColor = glm::vec3(1.0, 1.0, 1.0f); //0.9, 0.8, 0.7
    m_light = new Light(lightColor, *lightShader);
    m_light->Move(glm::vec3(-10, 10, 10.0));
    delete lightShader;

    //Player
    ShaderLoader* playerShader = new ShaderLoader();
    playerShader->Load("Player/playerShader");
    Model* playerModel = new Model(new ModelLoader("character"), new Texture("green", 1.0, 64));
    m_player = new Player(playerModel, *playerShader, 0, 0, 0);
    m_player->SetScale(0.25, 0.25, 0.25);
    delete playerShader;
}

void Scene::Update(const float& deltaTime)
{
	m_player->Update(deltaTime, m_camera, m_light, m_listTerrain[0]);
    m_renderer->Render(deltaTime, *m_camera, m_listTerrain, m_light);
    m_camera->Update(m_player->GetPosition(), m_player->GetRotation().y);
}