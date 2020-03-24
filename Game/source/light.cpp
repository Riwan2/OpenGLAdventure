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
    
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
    
    glBindVertexArray(m_VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, 192, vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 144, indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

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

void Light::Render()
{
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 44, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}


void Light::Move(const glm::vec3& position)
{
    m_position += position;
    m_model = glm::translate(m_model, position);
}

