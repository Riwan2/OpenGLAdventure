#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity/entity.h"
#include "../Basic/light.h"
#include "../Basic/camera.h"

class Player : public Entity
{
public:
    Player(Model*& model, const ShaderLoader& shaderLoader, const float& x, const float& y, const float& z);
    ~Player();
    
    void Update(const float& deltaTime, const Camera* camera, const Light* light);

private:
	float m_currentSpeed, m_currentTurnSpeed, m_currentUpwardSpeed;
	bool m_canJump;
    static constexpr float m_SPEED = 20;
    static constexpr const float m_TURN_SPEED = 120;
    static constexpr const float m_GRAVITY = -100;
    static constexpr const float m_JUMP_POWER = 30;
    static constexpr const float m_TERRAIN_HEIGHT = 0;
    
    void BasicRender(const Camera* camera, const Light* light);
};

#endif
