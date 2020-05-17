#ifndef PLAYERR_H
#define PLAYERR_H

#include "../Collision/collidableobject.h"
#include "../Basic/light.h"
#include "../Basic/input.h"

class Player : public collision::CollidableObject
{
public:
	Player(vaoLoader::VaoObject* model, txtl::Texture2d* texture, shld::ShaderObj* shader);
	~Player();
	glm::vec3 rotation;

	void Update(const float& deltaTime, const std::vector<collision::CollisionObject*>& boundaryList, Terrain* terrain);
	void Render(Camera* camera, const std::vector<light::PointLight*> listPointLight);
	void UpdateShader(Camera* camera, const std::vector<light::PointLight*> listPointLight);
private:
	float m_currentSpeed;
	bool m_canJump;
};

#endif //PLAYERR_H