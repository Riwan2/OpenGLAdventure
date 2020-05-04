#ifndef MOUSEPICKER_H
#define MOUSEPICKER_H

#include <glm/glm.hpp>
#include <iostream>
#include "../Basic/camera.h"
#include "../Basic/input.h"
#include "../Map/terrain.h"

class MousePicker
{
public:
	MousePicker();
	~MousePicker();

	void Update(const Camera& camera, Terrain* terrain);
	const glm::vec3& GetTerrainPoint() const { return m_terrainPoint; }
private:
	glm::vec3 m_currentRay, m_cameraPos, m_terrainPoint;
	glm::mat4 m_projection, m_view;

	glm::vec3 TerrainCollision(Terrain* terrain);
	glm::vec3 GetPointOnRay(const float& distance);
	glm::vec3 CalculateRay();
};

#endif //MOUSEPICKER_H