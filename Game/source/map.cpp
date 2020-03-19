#include "../headers/map.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Map::Map(const int& width, const int& height, const float& vertexSize)
{
    m_width = width;
    m_height = height;
    m_vertexSize = vertexSize;
    m_numVertices = m_width * m_height;
    m_numIndices = (m_width-1) * (m_height-1) * 6;
    
    m_vertices = new float[m_numVertices * 6];
    m_indices = new unsigned int[m_numIndices];
    
    CreateVertices();
    CreateIndices();
}

Map::~Map()
{
    delete m_vertices;
    delete m_indices;
}

void Map::CreateVertices()
{
    srand(time(NULL));
    
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            for (int i = 0; i < 6; i++) {
                int index = y * (m_width*6) + x * 6 + i;
                
                if (index % 6 == 0)
                    m_vertices[index] = x * m_vertexSize;
                else if (index % 6 == 1)
                    m_vertices[index] = 0.0f;//float(rand() % 10) / 10;
                else if (index % 6 == 2)
                    m_vertices[index] = y * m_vertexSize;
                else if (index % 6 == 3)
                    m_vertices[index] = 0.0f;
                else if (index % 6 == 4)
                    m_vertices[index] = 0.0f;
                else
                    m_vertices[index] = 0.0f;
            }
        }
    }
    
//     std::cout << "/////" << std::endl;
//     for (int i = 0; i < m_numVertices * 6; i++) {
//         std::cout << m_vertices[i];
//         if (i % 6 == 5) std::cout << std::endl;
//         else std::cout << " ; ";
//     }
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
    
//     std::cout << std::endl;
//      for (int i = 0; i < m_numIndices; i++) {
//         std::cout << m_indices[i];
//         if (i % 3 == 2) std::cout << std::endl;
//         else std::cout << " ; ";
//     }
}


