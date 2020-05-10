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
    delete m_mousePicker;
    delete m_quadTree;
	m_listPointLight.clear();
    m_listPointLight.shrink_to_fit();
	m_listTerrain.clear();
    m_listTerrain.shrink_to_fit();
}

stl::StaticObject* cube1;
stl::StaticObject* cube2;
stl::StaticObject* cube3;

collision::CollisionEntity* entity1;

std::vector<collision::CollisionShape*> listBoundary;

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
    delete blendMap;
    delete path;
    delete grass;
    delete terrainShader;

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
    m_renderer->Load(m_camera->GetProjection(), m_listTerrain[0]);

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

    //Player
    shld::ShaderObj* playerShader = new shld::ShaderObj(shld::Load("Player/playerShader"));
    Model* playerModel = new Model("character", txtl::Texture2d(txtl::Load2dJPGTexture("green")));
    m_player = new Player(playerModel, *playerShader, 0, 0, 0);
    m_player->SetScale(0.25, 0.25, 0.25);
    delete playerShader;

    //MousePicker
    m_mousePicker = new MousePicker();

    shld::ShaderObj* basicShader = new shld::ShaderObj(shld::Load("Basic/basicShader"));
    //vaoLoader::VaoObject object = vaoLoader::LoadBasicTriangle(glm::vec3(-10, 0, 0), glm::vec3(0, 2, 10), glm::vec3(10, 0, 0));
    vaoLoader::VaoObject object = vaoLoader::LoadBasicObj("cube");
    cube1 = new stl::StaticObject(object, txtl::Load2dJPGTexture("cube"), basicShader->programId);
    cube2 = new stl::StaticObject(vaoLoader::LoadBasicObj("sphere"), txtl::Load2dJPGTexture("cube"), basicShader->programId);
    cube3 = new stl::StaticObject(object, txtl::Load2dJPGTexture("cube"), basicShader->programId);
    // stl::SetModel(*cube1, glm::vec3(0.0), glm::vec3(5.0, 0.5, 5.0));

    // std::cout << "LeftSide : " << cube1->box.IntersectLeft(cube2->box) << std::endl;
    // std::cout << "RightSide : " << cube1->box.IntersectRight(cube2->box) << std::endl;
    // std::cout << "TopSide : " << cube1->box.IntersectTop(cube2->box) << std::endl;
    // std::cout << "BotSide : " << cube1->box.IntersectBot(cube2->box) << std::endl;
    // std::cout << "UpSide : " << cube1->box.IntersectUp(cube2->box) << std::endl;
    // std::cout << "DownSide : " << cube1->box.IntersectDown(cube2->box) << std::endl;
    //spl::SetModel(*cube, glm::vec3(10.0, -8.0, 0.0), glm::vec3(5.0, 0.5, 5.0));

    //stl::SetModel(*cube1, glm::vec3(10.0, 0.0, 0.0), glm::vec3(1.0), 0.0, 90.0, 0.0);
    stl::SetModel(*cube1, glm::vec3(10.0, 0.0, 0.0), glm::vec3(10.0, 0.5, 10.0), 30);
    stl::SetModel(*cube3, glm::vec3(10.0, 0.0, 0.0), glm::vec3(5.0, 1.0, 2.0));
    
    //boundary.Translate(cube1->simpleObject.model);
    //std::cout << "triangle : " << boundary.a.x << " ; " << boundary.b.x << " ; " << boundary.b.x << std::endl;

    //collision::Triangle boundary = collision::Triangle(glm::vec3(-10, 0, 0), glm::vec3(0, 5, 10), glm::vec3(10, 0, 0));
    listBoundary.push_back(new collision::CollisionShape(collision::CollisionShape(object.vertices, object.numVertices, object.indices, object.numIndices)));
    listBoundary[0]->Translate(cube1->simpleObject.model);

    listBoundary.push_back(new collision::CollisionShape(collision::CollisionShape(object.vertices, object.numVertices, object.indices, object.numIndices)));
    listBoundary[1]->Translate(cube3->simpleObject.model);

    stl::SetModel(*cube2, glm::vec3(0.5, 4.0, 0.5), glm::vec3(1.0, 1.0, 1.0));
    entity1 = new collision::CollisionEntity(collision::CollisionEntity(glm::vec3(0.5, 5.0, 0.5), glm::vec3(0.5, 1.0, 0.5)));
}

void Scene::Update(const float& deltaTime)
{
    m_mousePicker->Update(*m_camera, m_listTerrain[0]);
	m_player->Update(deltaTime, m_camera, m_listPointLight, m_listTerrain[0]);
    //QuadTree processing
    m_quadTree->clear();
    m_inRange.clear();
    m_inRange.shrink_to_fit();
    //Entity rendering plus update
    m_renderer->Render(deltaTime, *m_camera, m_listTerrain, m_listPointLight, *m_quadTree);

    //Static object
    glm::vec3 velocity = glm::vec3(0.0, 0.0, 0.0);
    if (Input::KeyDown(Input::eAction::jump)) {
        velocity.y += 0.5;
    }
    if (Input::KeyDown(Input::eAction::moveRight)) {
        velocity.x = 0.1f;
    } else if (Input::KeyDown(Input::eAction::moveLeft)) {
        velocity.x = -0.1f;
    }

    if (Input::KeyDown(Input::eAction::moveDown)) {
        velocity.z = 0.1f;
    } else if (Input::KeyDown(Input::eAction::moveUp)) {
        velocity.z = -0.1f;
    }

    entity1->CollideAndSlide(velocity, glm::vec3(0.0, -0.1, 0.0), listBoundary);
    glm::vec3 position = entity1->position / entity1->collisionObject.ellipsoidRadius;
    stl::SetModel(*cube2, position, glm::vec3(0.5, 1.0, 0.5));

    // float speed = 0.1;
    stl::Render(*cube1, *m_camera);
    stl::Render(*cube2, *m_camera);
    stl::Render(*cube3, *m_camera);
    // if (!cube2->box.IntersectDown(cube1->box, speed))
    //     cube2->simpleObject.position.y -= speed;

    // if (Input::KeyDown(Input::eAction::moveRight)) {
    //     cube2->simpleObject.position.x -= speed;
    // }
    // if (Input::KeyDown(Input::eAction::moveLeft)) {
    //     cube2->simpleObject.position.x += speed;
    // }
    // if (Input::KeyDown(Input::eAction::moveUp)) {
    //     cube2->simpleObject.position.z += speed;
    // }if (Input::KeyDown(Input::eAction::moveDown)) {
    //     cube2->simpleObject.position.z -= speed;
    // }

    // stl::SetModel(*cube2, cube2->simpleObject.position);

    // stl::Render(*cube1, *m_camera);
    // stl::Render(*cube2, *m_camera);
    //Mouse picker
    // m_quadTree->querry(data::Rectangle(m_mousePicker->GetTerrainPoint().x - 10, m_mousePicker->GetTerrainPoint().z - 10, 20),
    //  m_inRange);
    // for (int i = 0; i < m_inRange.size(); i++) {
    //     m_inRange[i].data->Move(0, 0.5, 0);
    // }

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