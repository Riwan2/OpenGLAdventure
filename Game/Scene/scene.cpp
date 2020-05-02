#include "scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{
	delete m_camera;
	delete m_renderer;
	delete m_player;
    delete m_skybox;
	m_listPointLight.clear();
    m_listPointLight.shrink_to_fit();
	m_listTerrain.clear();
    m_listTerrain.shrink_to_fit();
}

void Scene::Initialize()
{
	//Camera 
	m_camera = new Camera(30);

    //GLuint hello = txtl::LoadCubemapTexture(coucou)
    std::vector<std::string> facesFileName;
    facesFileName.push_back("right");
    facesFileName.push_back("left");
    facesFileName.push_back("top");
    facesFileName.push_back("bottom");
    facesFileName.push_back("front");
    facesFileName.push_back("back");
    m_skybox = new Skybox(shaderLoader::ShaderObj(shaderLoader::Load("Cubemap/cubemapShader")), facesFileName, 500);

    //Terrain
    shaderLoader::ShaderObj* terrainShader = new shaderLoader::ShaderObj(shaderLoader::Load("terrainShader"));
    txtl::Texture2d* grass = new txtl::Texture2d(txtl::Load2dJPGTexture("green"));
    txtl::Texture2d* path = new txtl::Texture2d(txtl::Load2dJPGTexture("path"));
    txtl::Texture2d* blendMap = new txtl::Texture2d(txtl::Load2dJPGTexture("blendmap"));
    m_listTerrain.push_back(new Terrain(-0.5, -0.5, 600, *terrainShader, grass, path, blendMap));
    delete blendMap;
    delete path;
    delete grass;
    delete terrainShader;

    //Water
    shaderLoader::ShaderObj* waterShader = new shaderLoader::ShaderObj(shaderLoader::Load("waterShader"));
    txtl::Texture2d* displacement = new txtl::Texture2d(txtl::Load2dJPGTexture("displacementmap"));
    txtl::Texture2d* water = new txtl::Texture2d(txtl::Load2dPNGTexture("heightmap"));
    m_water = new Water(-0.5, -0.5, 600, *waterShader, water, displacement);
    delete waterShader;
    delete displacement;
    delete water;

    //Entity
    m_renderer = new Renderer();
    m_renderer->Load(m_camera->GetProjection(), m_listTerrain[0]);

    //PointLight
    m_listPointLight.push_back(new light::PointLight(glm::vec3(1.0, 0.3, 0.3)));
    m_listPointLight.push_back(new light::PointLight(glm::vec3(0.3, 1.0, 0.3)));
    m_listPointLight.push_back(new light::PointLight(glm::vec3(0.1, 0.1, 1.0)));
    m_listPointLight.push_back(new light::PointLight(glm::vec3(1.0, 1.0, 1.0)));

    for (int i = 0; i < m_listPointLight.size(); i++) {
        m_listPointLight[i]->position = glm::vec3(i * 50, m_listTerrain[0]->GetMapHeight(i * 50, 10) + 10, 10);
    }

    //Player
    shaderLoader::ShaderObj* playerShader = new shaderLoader::ShaderObj(shaderLoader::Load("Player/playerShader"));
    Model* playerModel = new Model("character", new txtl::Texture2d(txtl::Load2dJPGTexture("green")));
    m_player = new Player(playerModel, *playerShader, 0, 0, 0);
    m_player->SetScale(0.25, 0.25, 0.25);
    delete playerShader;
}

void Scene::Update(const float& deltaTime)
{

	m_player->Update(deltaTime, m_camera, m_listPointLight, m_listTerrain[0]);
    m_renderer->Render(deltaTime, *m_camera, m_listTerrain, m_listPointLight);
    //glDisable(GL_CULL_FACE);

    //std::cout << 1/deltaTime << std::endl;
    // glEnable(GL_BLEND);
    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // m_water->Render(m_camera);
    // glDisable(GL_BLEND);

    m_skybox->Render(*m_camera, m_player->GetPosition());

    float height = m_listTerrain[0]->GetMapHeight(m_camera->GetPosition().x, m_camera->GetPosition().z);
    m_camera->Update(glm::vec3(m_player->GetPosition().x, m_player->GetTerrainHeight(), m_player->GetPosition().z),
        m_player->GetRotation().y, height);
}