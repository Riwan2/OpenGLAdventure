#include "player.h"
#include "../Basic/input.h"
#include "../Basic/parameters.h"

 Player::Player(Model*& model, const ShaderLoader& shaderLoader, const float& x, const float& y, const float& z) : Entity { model, shaderLoader, x, y, z }
 {
     SetRotation(0, 180, 0);
 }

 Player::~Player()
 {
     
 }
 
void Player::Update(const float& deltaTime, const Camera* camera, const Light* light)
{
    if (Input::KeyDown(Input::eAction::moveDown)) {
        Move(0, 0, m_SPEED * deltaTime);
    } else if (Input::KeyDown(Input::eAction::moveUp)) {
        Move(0, 0, -m_SPEED * deltaTime);
    }
    
    if (Input::KeyDown(Input::eAction::moveRight)) {
        Move(m_SPEED * deltaTime, 0, 0);
    } else if (Input::KeyDown(Input::eAction::moveLeft)) {
        Move(-m_SPEED * deltaTime, 0, 0);        
    }
    
    //Rotate(0, 0.3, 0);
    
    BasicRender(camera, light);
}

void Player::BasicRender(const Camera* camera, const Light* light)
{
    GetModel().Bind();
    m_shader->Use();
    m_shader->SetMat4("projection", camera->GetProjection());
    m_shader->SetMat4("view", camera->GetView());
    m_shader->SetVec3("lightPos", light->getPosition());
    m_shader->SetVec3("lightColor", light->getColor());
    m_shader->SetVec3("skyColor", parameters::skyColor);
    Entity::Update();
    GetModel().Render();
    GetModel().Unbind();
}

