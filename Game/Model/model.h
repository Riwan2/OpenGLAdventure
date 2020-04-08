#ifndef MODEL_H
#define MODEL_H

#include <GL/glew.h>
#include <GL/gl.h>

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Loader/stb_image.h"
#include "../Loader/shaderLoader.h"
#include "../Loader/shader.h"

class Model
{
public:
    Model();
    ~Model();
    
    void Load(const std::string& ModelFileName, const unsigned int& TextureId, ShaderLoader& shaderLoader);
    void Render(const glm::mat4& CameraProjection, const glm::mat4& cameraView, const glm::vec3& lightPos, const glm::vec3& lightColor);
    
    void Move(const float& x, const float& y, const float& z);
    void Rotate(const float& degree, const char& axes); //only x, y and z for axes
private:
    unsigned int m_VAO, m_VBO, m_EBO, m_Texture;
    int m_drawCall;
    Shader* m_shader;
    
    glm::mat4 m_model;
    glm::vec3 m_position;
    glm::vec3 m_rotation; //in degree
public:
    const glm::vec3& GetPosition() { return m_position; }
    const glm::vec3& GetRotation() { return m_rotation; }
};

#endif // MODEL_H
