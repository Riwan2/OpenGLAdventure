#ifndef VAOOBJECT_H
#define VAOOBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>
#include <GL/gl.h>

//VAO object with vertex, normal and indices

class VaoObject
{
public:
    VaoObject();
    ~VaoObject();
    
    void Initialize(float* vertices, int numVertices, unsigned int* indices, int numIndices);
    void Render();
private:
    GLuint m_VAO;
    GLuint m_VBO;
    GLuint m_EBO;
    int m_verticesSize;
    int m_indicesSize;
    int m_numVertices;
    int m_numIndices;
public:
    const int& getVerticesSize() { return m_verticesSize; }
    const int& getIndicesSize() { return m_indicesSize; }
};

#endif // VAOOBJECT_H
