#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <string.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>

class OBJLoader
{
public:
    OBJLoader(const std::string& fileName);
    ~OBJLoader();
    
    float* getVertices() { return vertices; }
    unsigned int* getIndices() { return indices; }
    int getVerticesSize() { return m_verticesSize; }
    int getIndicesSize() { return m_indicesSize; }
    int getDrawCall() { return m_drawCall; }
    
private:
    float* vertices;
    unsigned int* indices;
    int m_verticesSize;
    int m_indicesSize;
    int m_drawCall;
    
    void ProcessLine(const std::string& line, const std::vector<glm::vec3>& FileVertices, const std::vector<glm::vec3>& FileNormals, const std::vector<glm::vec2>& FileTexCoords, float* textureArray,float* normalsArray, std::vector<unsigned int>& FileIndices);
    void ProcessVertex(const glm::vec3& vertexData, const std::vector<glm::vec3>& FileVertices, const std::vector<glm::vec3>& FileNormals, const std::vector<glm::vec2>& FileTexCoords, float* textureArray,float* normalsArray, std::vector<unsigned int>& indices);
    
    glm::vec3 ParseFloat3(const std::string& line, const int& firstIndex);
    glm::vec2 ParseFloat2(const std::string& line);
    void ParseFloatData(const std::string& line, const int& firstIndex, int dataSize, float* container);
    void ParseIndexData(const std::string& line, unsigned int* container);
    
    void PrintData(const std::vector<glm::vec3>& FileVertices, const std::vector<glm::vec3>& FileNormals,
    const std::vector<glm::vec2>& FileTexCoords);
};

#endif // OBJLOADER_H
