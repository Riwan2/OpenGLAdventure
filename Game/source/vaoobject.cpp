#include "../headers/vaoobject.h"
#include <iostream>

VaoObject::VaoObject()
{

}

VaoObject::~VaoObject()
{
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
    glDeleteVertexArrays(1, &m_VAO);
}

void VaoObject::Initialize(float* vertices, int numVertices, unsigned int* indices, int numIndices)
{
    m_verticesSize = numVertices * 6 * sizeof(float);
    m_indicesSize = numIndices * sizeof(unsigned int);
    m_numVertices = numVertices;
    m_numIndices = numIndices;
    
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
    
    glBindVertexArray(m_VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, m_verticesSize, vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indicesSize, indices, GL_STATIC_DRAW);

    //Position
    glEnableVertexAttribArray(0);    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    //Normal
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    
    glBindVertexArray(0);
}

void VaoObject::Render()
{
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_numVertices + m_numIndices, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

