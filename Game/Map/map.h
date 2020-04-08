#ifndef MAP_H
#define MAP_H

#include <glm/glm.hpp>
#include "../Model/shader.h"
#include "../headers/vaoobject.h"

class Map
{
public:
    Map(const int& width, const int& height, const float& vertexSize, ShaderLoader& shaderLoader);
    ~Map();
    
    void Initialize(float* heightMap);
    void BasicRendering();
    
    float* GetVertices() { return m_vertices; }
    int GetNumVertices() { return m_numVertices; }
    int GetVerticesSize() { return m_numVertices * 6 * sizeof(float); }

    unsigned int* GetIndices() { return m_indices; }
    int GetIndicesSize() { return m_numIndices * sizeof(unsigned int); }
    
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }
    float getVertexSize() { return m_vertexSize; }
    int getCount() { return m_numIndices + m_numVertices; }

protected:
    Shader* m_shader;
    
private:
    float m_vertexSize;
    int m_width;
    int m_height;
    int m_numVertices;
    int m_numIndices;
    glm::vec3 m_normal;
    
    float* m_vertices;
    unsigned int* m_indices;
    VaoObject m_vaoObject;
    
    void CreateVertices(float* heightMap);
    void CreateIndices();
    void CreateNormals(float* heightMap);
    void CalculateNormal(const int& index, float* heightMap);
    void PrintVertices();
    void PrintIndices();
};

#endif // MAP_H
