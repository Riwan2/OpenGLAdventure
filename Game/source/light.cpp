#include "../headers/light.h"

#include <iostream>

unsigned int indices[] = {
    0, 1, 2,
    2, 3, 0,
    0, 4, 5,
    5, 1, 0,
    4, 5, 6,
    6, 7, 4,
    3, 2, 6,
    6, 7, 3,
    1, 2, 6,
    6, 5, 1,
    0, 3, 7,
    7, 4, 0,
};

Light::Light(const glm::vec3& color, const float& size)
{
    
    float vertices[] = {
        -0.5f * size,  0.5f * size,  0.0f, 0.0f, 0.0f, 0.0f,
        -0.5f * size, -0.5f * size,  0.0f, 0.0f, 0.0f, 0.0f,
         0.5f * size, -0.5f * size,  0.0f, 0.0f, 0.0f, 0.0f,
         0.5f * size,  0.5f * size,  0.0f, 0.0f, 0.0f, 0.0f,
        -0.5f * size,  0.5f * size, -1.0f * size, 0.0f, 0.0f, 0.0f,
        -0.5f * size, -0.5f * size, -1.0f * size, 0.0f, 0.0f, 0.0f,
         0.5f * size, -0.5f * size, -1.0f * size, 0.0f, 0.0f, 0.0f,
         0.5f * size,  0.5f * size, -1.0f * size, 0.0f, 0.0f, 0.0f,
    };
    
    m_vaoObject.Initialize(vertices, 8, indices, 36);

    m_model = glm::mat4(1.0f);
    m_position = glm::vec3(0.0, 0.0f, 0.0);
    
    m_color = color;
}

Light::~Light()
{
    glDeleteBuffers(192, &m_VBO);
    glDeleteBuffers(144, &m_EBO);
    glDeleteVertexArrays(1, &m_VAO);
}

void Light::Render(const glm::mat4& projection, const glm::mat4& cameraView)
{
    m_shader.Use();
    m_shader.SetMat4("projection", projection);
    m_shader.SetMat4("view", cameraView);
    m_shader.SetMat4("model", m_model);
    m_shader.SetVec3("lightColor", m_color);
    
    m_vaoObject.Render();
}


void Light::Move(const glm::vec3& position)
{
    m_position += position;
    m_model = glm::translate(m_model, position);
}

