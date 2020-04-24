#ifndef MAP_H
#define MAP_H

#include "../Model/shader.h"
#include "../Basic/basicStruct.h"
#include "../Loader/texture.h"

class Map
{
public:
    Map(const float& posX, const float& posZ, const float& size);
    ~Map();
    
    void Initialize(float* heightMap);
    void BasicRendering();
    float GetHeight(const int& x, const int& z);
    float GetMapHeight(const float& worldX, const float& worldZ);

    float GetSize() { return m_size; }
    float GetVerticesSize() { return m_verticesSize; }
    int& GetNumVertices() { return m_numVertices; }
    inline int GetPosX() { return m_posX; }
    inline int GetPosZ() { return m_posZ; }
protected:
    float* m_heightMap;
    int m_heightMapWidth, m_heightMapHeight, m_maxHeight;
private:
    float m_posX, m_posZ, m_size, m_verticesSize;
    int m_width, m_height, m_numVertices, m_numIndices;

    basic::Vertex* m_vertex;
    unsigned int* m_indices;

    GLuint m_VAO, m_VBO, m_EBO;
    int m_drawCall;
    
    float barryCentric(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec2 pos); //Triangle interpolation
    void CreateVertices(float* heightMap);
    void CreateIndices();
    glm::vec3 CalculateNormal(const int& x, const int& z, float* heightMap);
    void PrintVertices();
    void PrintIndices();
};

#endif // MAP_H
