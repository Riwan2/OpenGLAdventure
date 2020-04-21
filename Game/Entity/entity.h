#ifndef ENTITY_H
#define ENTITY_H

#include "../Model/shader.h"
#include "../Model/model.h"

class Entity
{
public:
    Entity(Model*& model, const ShaderLoader& shaderLoader, const float& x, const float& y, const float& z, const bool& fakeLighting = false);
    ~Entity();
    
    void Update();
    void Move(const float& x, const float& y, const float& z);
    void Rotate(const float& degreeX, const float& degreeY, const float& degreeZ);
    void Scale(const float& x, const float& y, const float& z);
    
protected:
    Shader* m_shader;
    glm::vec3 m_position;
    glm::vec3 m_scale;
    glm::vec3 m_rotation; //in degree
private:
    Model* m_model;
    float m_time;
    float m_fakeLighting;
    int m_textureIndex;
    
    glm::mat4 m_transformation;
    void SetTransformation();
    
public:
    Model& GetModel() { return *m_model; }
    const glm::vec3& GetPosition() { return m_position; }
    const glm::vec3& GetScale() { return m_scale; }
    const glm::vec3& GetRotation() { return m_rotation; }

    inline void SetTextureIndex(const int& index) { m_textureIndex = index; }
    inline void SetPosition(const float& x, const float& y, const float& z) {
        m_position = glm::vec3(x, y, z);
        SetTransformation();
    }
    inline void SetRotation(const float& degreeX, const float& degreeY, const float& degreeZ) {
        m_rotation = glm::vec3(degreeX, degreeY, degreeZ);
        SetTransformation();
    }
    inline void SetScale(const float& x, const float& y, const float& z) {
        m_scale = glm::vec3(x, y, z);
        SetTransformation(); 
    }
};

#endif // ENTITY_H
