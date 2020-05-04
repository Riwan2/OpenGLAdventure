#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity/entity.h"
#include "../Basic/light.h"
#include "../Basic/camera.h"
#include "../Map/terrain.h"

class Player : public Entity
{
public:
    Player(Model*& model, const shld::ShaderObj& shaderObj, const float& x, const float& y, const float& z);
    ~Player();
    
    void Update(const float& deltaTime, const Camera* camera, const std::vector<light::PointLight*> listPointLight, Terrain* terrain);
    inline float GetTerrainHeight() { return m_terrainHeight; }

private:
	float m_currentSpeed, m_currentTurnSpeed, m_currentUpwardSpeed;
    float m_terrainHeight;
	bool m_canJump;
    static constexpr float m_SPEED = 20;
    static constexpr const float m_TURN_SPEED = 100;
    static constexpr const float m_GRAVITY = -100;
    static constexpr const float m_JUMP_POWER = 20;
    
    void BasicRender(const Camera* camera, const std::vector<light::PointLight*> listPointLight);
    void TerrainCollision(Terrain* terrain);
};

#endif
