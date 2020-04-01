#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>
#include <GL/gl.h>

#include "../headers/shader.h"
#include "../headers/camera.h"
#include "../headers/vaoobject.h"

class Light
{
public:
    Light(const glm::vec3& color, const float& size = 1.0f);
    ~Light();
    
    void Move(const glm::vec3& position);
    void Render(const glm::mat4& projection, const glm::mat4& cameraView);
    glm::mat4* getModel() { return &m_model; }
    glm::vec3* getPosition() { return &m_position; }
    glm::vec3* getColor() { return &m_color; }
    GLuint m_VAO;

private:
    GLuint m_VBO;
    GLuint m_EBO;
    Shader m_shader = Shader("../Shader/lightShader");
    VaoObject m_vaoObject;
    
    glm::mat4 m_model;
    glm::vec3 m_position;
    glm::vec3 m_color;
};

#endif // LIGHT_H
