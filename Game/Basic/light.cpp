#include "light.h"

Light::Light(const glm::vec3& color, ShaderLoader& shaderLoader, const float& size)
{
    int numIndices = 36;
    int numVertices = 8;
    int verticesSize = 6;
    m_drawCall = numIndices;

    float* vertices = new float[numVertices * verticesSize] {
        -0.5f * size,  0.5f * size,  0.0f,
        -0.5f * size, -0.5f * size,  0.0f,
         0.5f * size, -0.5f * size,  0.0f,
         0.5f * size,  0.5f * size,  0.0f,
        -0.5f * size,  0.5f * size, -1.0f * size,
        -0.5f * size, -0.5f * size, -1.0f * size,
         0.5f * size, -0.5f * size, -1.0f * size, 
         0.5f * size,  0.5f * size, -1.0f * size,
    };

    unsigned int* indices = new unsigned int[numIndices] {
        0, 1, 2,
        2, 3, 0,
        0, 4, 5,
        5, 1, 0,
        4, 7, 6,
        6, 5, 4,
        3, 2, 6,
        6, 7, 3,
        1, 5, 6,
        6, 2, 1,
        0, 3, 7,
        7, 4, 0,
    };

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
    
    glBindVertexArray(m_VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO); //Vertices
    glBufferData(GL_ARRAY_BUFFER, numVertices * verticesSize * sizeof(float), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); //Triangle Indices
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0); //Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        
    glBindVertexArray(0);
    
    delete[] vertices;
    delete[] indices;

    m_shader = new Shader(shaderLoader);
    m_model = glm::mat4(1.0f);
    m_position = glm::vec3(0.0, 0.0f, 0.0);
    
    m_color = color;
}

Light::~Light()
{
    delete m_shader;

    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
    glDeleteVertexArrays(1, &m_VAO);
}

void Light::Render(const glm::mat4& projection, const glm::mat4& cameraView)
{
    m_shader->Use();
    m_shader->SetMat4("projection", projection);
    m_shader->SetMat4("view", cameraView);
    m_shader->SetMat4("model", m_model);
    m_shader->SetVec3("lightColor", m_color);

    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_drawCall, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);   
}


void Light::Move(const glm::vec3& position)
{
    m_position += position;
    m_model = glm::translate(m_model, position);
}

