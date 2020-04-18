#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity/entity.h"
#include "../headers/light.h"
#include "../Basic/camera.h"

class Player : public Entity
{
    public:
        Player(Model*& model, const ShaderLoader& shaderLoader, const float& x, const float& y, const float& z);
        ~Player();
        
        void Update(const float& deltaTime, const Camera* camera, const Light* light);

    private:
        static constexpr float m_SPEED = 20;
        static const float m_TURN;
        
        void BasicRender(const Camera* camera, const Light* light);
};

#endif
