#include "map.h"
#include <iostream>

Map::Map(const int& width, const int& height, const float& vertexSize)
{
    m_width = width;
    m_height = height;
    m_vertexSize = vertexSize;
    m_numVertices = m_width * m_height;
    m_numIndices = (m_width-1) * (m_height-1) * 6;
    m_normal = glm::vec3(1.0f);
    
    m_vertices = new float[m_numVertices * 6];
    m_indices = new unsigned int[m_numIndices];
}

Map::~Map()
{
    delete m_vertices;
    delete m_indices;
}

void Map::Initialize(float* heightMap)
{
    CreateVertices(heightMap);
    CreateIndices();
    CreateNormals(heightMap);
    
    m_vaoObject.Initialize(m_vertices, m_numVertices, m_indices, m_numIndices);
}

void Map::BasicRendering() 
{
    m_vaoObject.Render();
}

void Map::CreateVertices(float* heightMap)
{
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            for (int i = 0; i < 3; i++) {
                int index = y * (m_width*6) + x * 6 + i;
    
                if (index % 3 == 0)
                    m_vertices[index] = x * m_vertexSize;
                else if (index % 3 == 1) 
                    m_vertices[index] = heightMap[y * m_width + x];
                else if (index % 3 == 2) 
                    m_vertices[index] = y * m_vertexSize;
            }
        }
    }
    //PrintVertices();
}

void Map::CreateNormals(float* heightMap)
{
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            int vertexIndex = y * (m_width * 6) + x * 6;
            CalculateNormal(vertexIndex / 6, heightMap);
            
            for (int i = 0; i < 3; i++) {
                int index = y * (m_width*6) + x * 6 + i + 3;
                
                if (index % 3 == 0)
                    m_vertices[index] = m_normal.x;
                else if (index % 3 == 1)
                    m_vertices[index] = m_normal.y;
                else if (index % 3 == 2)
                    m_vertices[index] = m_normal.z;
            }
        }
    }
    //PrintVertices();
}


void Map::CalculateNormal(const int& index, float* heightMap)
{
    float v1, v2, v3, v4;
    int x = index % m_width;
    int y = index / m_width;
    
    if (x > 0 && x < m_width-1 && y > 0 && y < m_height-1) {
        v1 = heightMap[index-1];
        v2 = heightMap[index + 1];
        v3 = heightMap[index + m_width];
        v4 = heightMap[index - m_width];
    
        glm::vec3 normal = glm::vec3(v1 - v2, 2.0f, v3 - v4);
        m_normal = glm::normalize(normal);
    } else {
        m_normal = glm::vec3(0.0f, 1.0f, 0.0f);
    }
}

void Map::CreateIndices()
{
    for (int y = 0; y < m_height-1; y++) {
        for (int  x = 0; x < m_width-1; x++) {
            int index = y * m_width + x;
            for (int i = 0; i < 6; i++) {
                int indice_index = y * (m_width-1) * 6 + x * 6 + i;
                if (i % 6 == 0) {
                    m_indices[indice_index] = index;
                } else if (i % 6 == 1) {
                    m_indices[indice_index] = index + m_width;
                } else if (i % 6 == 2) {
                    m_indices[indice_index] = index + m_width + 1;
                } else if (i % 6 == 3) {
                    m_indices[indice_index] = index + m_width + 1;
                } else if (i % 6 == 4) {
                    m_indices[indice_index] = index + 1;
                } else {
                    m_indices[indice_index] = index;
                }
            }
        }
    }
    //PrintIndices();
}

void Map::PrintVertices()
{
    std::cout << "Vertices :" << std::endl;
    for (int i = 0; i < m_numVertices * 6; i++) {
        std::cout << m_vertices[i];
        if (i % 6 == 5) std::cout << std::endl;
        else std::cout << " ; ";
    }
}

void Map::PrintIndices()
{    
    std::cout << "Indices :" << std::endl;
    for (int i = 0; i < m_numIndices; i++) {
         std::cout << m_indices[i];
         if (i % 3 == 2) std::cout << std::endl;
         else std::cout << " ; ";
    }
}







