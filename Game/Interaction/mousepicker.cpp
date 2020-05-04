#include "mousepicker.h"
#include "../Basic/parameters.h"

const float RAY_DISTANCE = 600;
const float TERRAIN_COLLISION_TEST = 300;

MousePicker::MousePicker()
{
	m_cameraPos = glm::vec3(0.0);
	m_currentRay = glm::vec3(0.0);
}

MousePicker::~MousePicker()
{

}

void MousePicker::Update(const Camera& camera, Terrain* terrain)
{
	m_view = camera.GetView();
	m_projection = camera.GetProjection();
	m_currentRay = CalculateRay();
	m_cameraPos = camera.GetPosition();

	m_terrainPoint = TerrainCollision(terrain);
}

glm::vec3 MousePicker::GetPointOnRay(const float& distance)
{
	glm::vec3 scaledRay = glm::vec3(m_currentRay.x * distance, m_currentRay.y * distance, m_currentRay.z * distance);
	return scaledRay + m_cameraPos;
}

glm::vec3 MousePicker::TerrainCollision(Terrain* terrain)
{
	glm::vec3 point;
	float terrainHeight, distance = 0;

	for (int i = 0; i < TERRAIN_COLLISION_TEST; i++) {
		if (distance > RAY_DISTANCE) { 
			point = GetPointOnRay(RAY_DISTANCE);
			terrainHeight = terrain->GetMapHeight(point.x, point.z);
			break;
		}
		point = GetPointOnRay(distance);
		terrainHeight = terrain->GetMapHeight(point.x, point.z);
		distance += point.y - terrainHeight;
	}

	return glm::vec3(point.x, terrainHeight, point.z);
}

glm::vec3 MousePicker::CalculateRay()
{
	//Viewport space
	float mouseX = Input::MousePosition().X;
	float mouseY = Input::MousePosition().Y;
	//OpenGL Coordinate system
	float x = (mouseX * 2) / parameters::Width - 1;
	float y = -((mouseY * 2) / parameters::Height - 1);
	//Clip Space
	glm::vec4 clipCoords = glm::vec4(x, y, -1.0, 1.0);
	//Eye Space
	glm::mat4 invertedProjection = glm::inverse(m_projection);
	glm::vec4 eyeCoords = invertedProjection * clipCoords;
	eyeCoords = glm::vec4(eyeCoords.x, eyeCoords.y, -1.0, 0.0);
	//World Space
	glm::mat4 invertedView = glm::inverse(m_view);
	glm::vec4 worldCoords = invertedView * eyeCoords;	
	glm::vec3 worldRay = glm::normalize(glm::vec3(worldCoords));
	return worldRay;
}