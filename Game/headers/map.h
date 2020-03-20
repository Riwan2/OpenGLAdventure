#ifndef MAP_H
#define MAP_H

#include <glm/glm.hpp>

class Map
{
public:
    Map(const int& width, const int& height, const float& vertexSize);
    ~Map();
    
    float* GetVertices() { return m_vertices; }
    int GetVerticesSize() { return m_numVertices * 6 * sizeof(float); }

    unsigned int* GetIndices() { return m_indices; }
    int GetIndicesSize() { return m_numIndices * sizeof(unsigned int); }
    
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }
    float getVertexSize() { return m_vertexSize; }
    int getCount() { return m_numIndices + m_numVertices; }
    
private:
    float m_vertexSize;
    int m_width;
    int m_height;
    int m_numVertices;
    int m_numIndices;
    glm::vec3 m_normal;
    
    float* m_vertices;
    unsigned int* m_indices;
    float* m_heightMap;
    
    void CreateVertices();
    void CreateIndices();
    void CreateNormals();
    void CalculateNormal(const int& index);
};

#endif // MAP_H
