#include "entity.h"
#include "../Basic/parameters.h"

Entity::Entity(const Model& model, const ShaderLoader& shaderLoader, const float& x, const float& y, const float& z)
{
    m_model = new Model(model);
    m_shader = new Shader(shaderLoader);
    
    m_transformation = glm::mat4(1.0);
    m_position = glm::vec3(x, y, z);
    m_scale = glm::vec3(1.0);
    m_rotation = glm::vec3(0.0);
    SetTransformation();
}

Entity::~Entity()
{
    delete m_shader;
    delete m_model;
}

void Entity::Update()
{
    m_shader->Use();
    m_shader->SetMat4("model", m_transformation);
    m_shader->SetFloat("reflectivity", m_model->GetTexture().getReflectivity());
    m_shader->SetFloat("shineDamper", m_model->GetTexture().getShineDamper());
    m_shader->SetVec3("skyColor", parameters::skyColor);
}

void Entity::SetTransformation() {
    m_transformation = glm::mat4(1.0);
    m_transformation = glm::scale(m_transformation, m_scale);
    m_transformation = glm::translate(m_transformation, m_position);
    m_transformation = glm::rotate(m_transformation, (float)glm::radians(m_rotation.x), glm::vec3(0, 1, 0));
    m_transformation = glm::rotate(m_transformation, (float)glm::radians(m_rotation.y), glm::vec3(0, 1, 0));
    m_transformation = glm::rotate(m_transformation, (float)glm::radians(m_rotation.z), glm::vec3(0, 1, 0));
}

void Entity::Move(const float& x, const float& y, const float& z)
{
    m_position += glm::vec3(x, y, z);
    SetTransformation();
}

void Entity::Rotate(const float& degreeX, const float& degreeY, const float& degreeZ)
{
    m_rotation += glm::vec3(degreeX, degreeY, degreeZ);
    if (m_rotation.x < 0) m_rotation += 360;
    else if (m_rotation.x > 360) m_rotation -= 360;
    if (m_rotation.y < 0) m_rotation += 360;
    else if (m_rotation.y > 360) m_rotation -= 360;
    if (m_rotation.z < 0) m_rotation += 360;
    else if (m_rotation.z > 360) m_rotation -= 360;
    SetTransformation();
}
