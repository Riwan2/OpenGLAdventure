#ifndef MAP_H
#define MAP_H

#include <glm/glm.hpp>
#include "../Model/shader.h"
#include "../headers/vaoobject.h"
#include "../Basic/basicStruct.h"

class Map
{
public:
    Map(const float& size, ShaderLoader& shaderLoader);
    ~Map();
    
    void Initialize(float* heightMap);
    void BasicRendering();

    float getSize() { return m_size; }
    int& GetNumVertices() { return m_numVertices; }

protected:
    Shader* m_shader;
    
private:
    float m_size;
    int m_width, m_height, m_numVertices, m_numIndices;
    glm::vec3 m_normal;

    basic::Vertex* m_vertex;
    unsigned int* m_indices;

    GLuint m_VAO, m_VBO, m_EBO;
    int m_drawCall;
    
    void CreateVertices(float* heightMap);
    void CreateIndices();
    void CreateNormals(float* heightMap);
    void CalculateNormal(const int& index, float* heightMap);
    void PrintVertices();
    void PrintIndices();
};

#endif // MAP_H
