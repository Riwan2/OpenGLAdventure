#ifndef MODEL_H
#define MODEL_H

#include <GL/glew.h>

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Model/shader.h"
#include "../Loader/modelloader.h"

class Model
{
public:
    Model();
    ~Model();
    
    void Load(const ModelLoader& modelLoader, const unsigned int& TextureId, const ShaderLoader& shaderLoader);
    void Render(const glm::mat4& CameraProjection, const glm::mat4& cameraView, const glm::vec3& lightPos, const glm::vec3& lightColor);
    
    void Move(const float& x, const float& y, const float& z);
    void Scale(const float& x, const float& y, const float& z);
    void Rotate(const float& degree, const char& axes); //only x, y and z for axes
private:
    GLuint m_VAO, m_VBO, m_EBO, m_Texture;
    int m_drawCall;
    Shader* m_shader;
    
    glm::mat4 m_model;
    glm::vec3 m_position;
    glm::vec3 m_scale;
    glm::vec3 m_rotation; //in degree
public:
    const glm::vec3& GetPosition() { return m_position; }
    const glm::vec3& GetScale() { return m_scale; }
    const glm::vec3& GetRotation() { return m_rotation; }
};

#endif // MODEL_H
