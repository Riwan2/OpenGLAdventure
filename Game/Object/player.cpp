#include "player.h"
#include "../Basic/parameters.h"

const float SPEED = 0.5;
const float MAXSPEED = 0.7;
const float ACCELERATION = 0.04;
const float FRICTION = 0.85f;
const float ROTATIONSPEED = 3.0;
const float TURNSLOW = 0.95;

Player::Player(vaoLoader::VaoObject* model, txtl::Texture2d* texture, shld::ShaderObj* shader) : CollidableObject(model, texture, shader)
{
	m_canJump = true;
	m_currentSpeed = SPEED;
	CollidableObject::SetRotation(glm::vec3(0, 180, 0));
	CollidableObject::SetGravity(glm::vec3(0.0, -0.1, 0.0));
	CollidableObject::SetOffsetY(0.1);
	rotation = glm::vec3(0.0);
}

Player::~Player()
{

}

void Player::Update(const float& deltaTime, const std::vector<collision::CollisionObject*>& boundaryList, Terrain *terrain)
{
	static glm::vec3 velocity;

	glm::vec3 angularVelocity = glm::vec3(0.0);
	angularVelocity.x = sin(glm::radians(GetRotation().y)) * m_currentSpeed;
	angularVelocity.z = cos(glm::radians(GetRotation().y)) * m_currentSpeed;

	if (Input::KeyDown(Input::eAction::moveUp)) {
		if (velocity.x > MAXSPEED) velocity.x = MAXSPEED;
		else velocity.x += angularVelocity.x * ACCELERATION;
		if (velocity.z > MAXSPEED)  velocity.z = MAXSPEED;
		else velocity.z += angularVelocity.z * ACCELERATION;
	} else if (Input::KeyDown(Input::eAction::moveDown)) {
		if (velocity.x < -MAXSPEED) velocity.x = -MAXSPEED;
		else velocity.x += -angularVelocity.x * ACCELERATION;
		if (velocity.z < -MAXSPEED) velocity.z = -MAXSPEED;
		else velocity.z += -angularVelocity.z * ACCELERATION;
	} else {
		velocity.z *= FRICTION;
		velocity.x *= FRICTION;
	}

	if (Input::KeyDown(Input::eAction::moveRight)) {
		rotation.y -= ROTATIONSPEED;
		if (rotation.y > 360) rotation.y -= 360;
		if (rotation.y < 0) rotation.y += 360;
		velocity.x *= TURNSLOW;
		velocity.z *= TURNSLOW;
	} else if (Input::KeyDown(Input::eAction::moveLeft)) {
		rotation.y += ROTATIONSPEED;
		if (rotation.y > 360) rotation.y -= 360;
		if (rotation.y < 0) rotation.y += 360;
		velocity.x *= TURNSLOW;
		velocity.z *= TURNSLOW;
	}

	if (GroundTouched() && velocity.y < 0) m_canJump = true;

	if (Input::KeyDown(Input::eAction::jump) && m_canJump) {
		m_currentSpeed = SPEED * 1.1;
        velocity.y = 1.2;
        m_canJump = false;
	}

	if (!m_canJump && velocity.y > -0.25)
		velocity.y += GetGravity().y / 2;
	else if (m_canJump) {
		velocity.y = 0;
		m_currentSpeed = SPEED;
	}

	if (GetPosition().y < - 10) SetPosition(glm::vec3(0, 10, 0));

	CollidableObject::SetVelocity(velocity);
	CollidableObject::Update(boundaryList, terrain);
}

void Player::Render(Camera *camera, const std::vector<light::PointLight *> listPointLight)
{
	CollidableObject::BindShader();
	UpdateShader(camera, listPointLight);
	CollidableObject::Render(camera);
}

void Player::UpdateShader(Camera *camera, const std::vector<light::PointLight *> listPointLight)
{
	shld::SetMat4(*GetShader(), "model", GetModel());
	shld::SetMat4(*GetShader(), "projection", camera->GetProjection());
	shld::SetMat4(*GetShader(), "view", camera->GetView());
	shld::SetVec3(*GetShader(), "skyColor", parameters::skyColor);
	shld::SetFloat(*GetShader(), "reflectivity", GetTexture().reflectivity);
	shld::SetFloat(*GetShader(), "shineDamper", GetTexture().shineDamper);   
	light::LoadLigthIntoShader(GetShader(), listPointLight);
}