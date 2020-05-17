#include "scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{
	delete m_camera;
	//delete m_renderer;
	delete m_player;
    delete m_skybox;
    delete m_mousePicker;
    delete m_quadTree;
	m_listPointLight.clear();
    m_listPointLight.shrink_to_fit();
	//m_listTerrain.clear();
    //m_listTerrain.shrink_to_fit();
}

collision::CollidableObject* myCollidableObject;
std::vector<collision::CollisionObject*> listBoundary;

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
    m_skybox = new Skybox(shld::ShaderObj(shld::Load("Cubemap/cubemapShader")), facesFileName, 500);

    //Terrain
    shld::ShaderObj* terrainShader = new shld::ShaderObj(shld::Load("terrainShader"));
    txtl::Texture2d* grass = new txtl::Texture2d(txtl::Load2dJPGTexture("green"));
    txtl::Texture2d* path = new txtl::Texture2d(txtl::Load2dJPGTexture("path"));
    txtl::Texture2d* blendMap = new txtl::Texture2d(txtl::Load2dJPGTexture("blendmap"));
    m_listTerrain.push_back(new Terrain(-0.5, -0.5, 600, *terrainShader, grass, path, blendMap));

    //Water
    shld::ShaderObj* waterShader = new shld::ShaderObj(shld::Load("waterShader"));
    txtl::Texture2d* displacement = new txtl::Texture2d(txtl::Load2dJPGTexture("displacementmap"));
    txtl::Texture2d* water = new txtl::Texture2d(txtl::Load2dPNGTexture("heightmap"));
    m_water = new Water(-0.5, -0.5, 600, *waterShader, water, displacement);
    delete waterShader;
    delete displacement;
    delete water;

    //Entity
    m_renderer = new Renderer();
    //Test :
    //m_renderer->Load(m_camera->GetProjection(), m_listTerrain[0]);

    //QuadTree
    m_quadTree = new data::QuadTree(data::Rectangle(m_listTerrain[0]->GetPosX(), m_listTerrain[0]->GetPosZ(), m_listTerrain[0]->GetSize()));

    //PointLight
    m_listPointLight.push_back(new light::PointLight(glm::vec3(1.0, 0.3, 0.3)));
    m_listPointLight.push_back(new light::PointLight(glm::vec3(0.3, 1.0, 0.3)));
    m_listPointLight.push_back(new light::PointLight(glm::vec3(0.1, 0.1, 1.0)));
    m_listPointLight.push_back(new light::PointLight(glm::vec3(1.0, 1.0, 1.0)));

    for (int i = 0; i < m_listPointLight.size(); i++) {
        m_listPointLight[i]->position = glm::vec3(i * 50, m_listTerrain[0]->GetMapHeight(i * 50, 10) + 10, 10);
    }

    //Collision : 
    shld::ShaderObj* basicShader = new shld::ShaderObj(shld::Load("Basic/basicShader"));
    shld::ShaderObj* debugShader = new shld::ShaderObj(shld::Load("Debug/debugShader"));
    vaoLoader::VaoObject cubeModel = vaoLoader::LoadBasicObj("cube");
    vaoLoader::VaoObject player = vaoLoader::LoadBasicObj("character");
    txtl::Texture2d cubeTexture = txtl::Load2dJPGTexture("cube");

    myCollidableObject = new collision::CollidableObject(&player, &cubeTexture, basicShader);
    //myCollidableObject->InitDebugMode(&cubeModel, debugShader);
    myCollidableObject->SetGravity(glm::vec3(0.0, -0.1, 0.0));
    myCollidableObject->SetOffsetY(0.1);

    //Player
    shld::ShaderObj* playerShader = new shld::ShaderObj(shld::Load("Player/playerShader"));
    m_player = new Player(&player, &cubeTexture, playerShader);
    //m_player->InitDebugMode(&cubeModel, debugShader);

    vaoLoader::VaoObject* platform = new vaoLoader::VaoObject(vaoLoader::LoadBasicObj("platform"));
    vaoLoader::VaoObject* platformShape = new vaoLoader::VaoObject(vaoLoader::LoadBasicObj("platformShape"));
    txtl::Texture2d* houseTexture = new txtl::Texture2d(txtl::Load2dJPGTexture("decor/platform")); 
    
    //cCollision bounding object : 
    collision::CollisionObject* collisionObject = new collision::CollisionObject(platform, platformShape, houseTexture, basicShader);
    //collisionObject->InitDebugMode(&cubeModel, debugShader);
    collisionObject->SetPosition(glm::vec3(0.0, -5.0f, 0.0));
    //collisionObject->SetScale(glm::vec3(2.0));
    //collisionObject->SetBoundingBoxOffset(glm::vec3(1.5, 2.5, 1.5));
    listBoundary.push_back(collisionObject);

    //List PLatfform:
    collisionObject = new collision::CollisionObject(platform, platformShape, houseTexture, basicShader);
    collisionObject->SetPosition(glm::vec3(7.0, -2.0, 45.0));
    collisionObject->SetScale(glm::vec3(0.5f, 1.0f, 0.5f));
    //collisionObject->InitDebugMode(&cubeModel, debugShader);
    listBoundary.push_back(collisionObject);

    //MousePicker
    m_mousePicker = new MousePicker();
}

void Scene::Update(const float& deltaTime)
{
    m_mousePicker->Update(*m_camera, m_listTerrain[0]);
    //QuadTree processing
    m_quadTree->clear();
    m_inRange.clear();
    m_inRange.shrink_to_fit();
    //Entity rendering plus update
    //m_renderer->Render(deltaTime, *m_camera, m_listTerrain, m_listPointLight, *m_quadTree);

    //Static object
    m_player->Update(deltaTime, listBoundary, m_listTerrain[0]);
    m_player->Render(m_camera, m_listPointLight);
    m_player->SetRotation(glm::vec3(0, 90 - m_camera->GetAngleAround() + m_player->rotation.y, 0));

    //listBoundary[0]->Rotate(glm::vec3(0.0, 0.2, 0.0));
    // myCollidableObject->Render(m_camera);
    // myCollidableObject->SetVelocity(velocity);
    // myCollidableObject->Update(listBoundary, m_listTerrain[0]);

    //glDisable(GL_CULL_FACE);

    //std::cout << 1/deltaTime << std::endl;
    // glEnable(GL_BLEND);
    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // m_water->Render(m_camera);
    // glDisable(GL_BLEND);
    for (int i = 0; i < listBoundary.size(); i++) {
        listBoundary[i]->Render(m_camera);
    }

    m_skybox->Render(*m_camera, m_player->GetPosition());

    float height = m_listTerrain[0]->GetMapHeight(m_camera->GetPosition().x, m_camera->GetPosition().z);
    m_camera->Update(glm::vec3(m_player->GetPosition().x, 2, m_player->GetPosition().z),
        m_player->rotation.y, height);
}