#include "map.h"
#include <iostream>

Map::Map(const float& size, ShaderLoader& shaderLoader, int textureId)
{
    m_textureId = textureId;
    m_width = 16;
    m_height = 16;
    m_size = size;
    m_numVertices = m_width * m_height;
    m_numIndices = (m_width-1) * (m_height-1) * 6;
    m_normal = glm::vec3(1.0f);
    
    m_vertex = new basic::Vertex[m_numVertices];
    m_indices = new unsigned int[m_numIndices];
    m_shader = new Shader(shaderLoader);
}

Map::~Map()
{
    delete m_indices;
    delete m_shader;
    delete m_vertex;
}

void Map::Initialize(float* heightMap)
{
    CreateVertices(heightMap);
    CreateIndices();
    //CreateNormals(heightMap);

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
    
    glBindVertexArray(m_VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO); //Vertices
    glBufferData(GL_ARRAY_BUFFER, m_numVertices * sizeof(basic::Vertex) * sizeof(float), m_vertex, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); //Triangle Indices
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_numIndices * sizeof(unsigned int), m_indices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0); //Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(1); //Normals
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    
    glEnableVertexAttribArray(2); //Texture Position
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        
    glBindVertexArray(0);
}

void Map::BasicRendering() 
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_textureId);
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_numIndices, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glDisable(GL_TEXTURE_2D);
}

void Map::CreateVertices(float* heightMap)
{
    m_size = 1;
    int index = 0;
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            m_vertex[index].PosX = (float)x / (float)(m_width-1) * m_size;
            m_vertex[index].PosY = 0;
            m_vertex[index].PosZ = (float)y / (float)(m_height-1) * m_size;
            m_vertex[index].NormX = 0;
            m_vertex[index].NormY = 1;
            m_vertex[index].NormZ = 0;
            m_vertex[index].TexCoordX = (float)x / (float)(m_width-1);
            m_vertex[index].TexCoordY = (float)y / (float)(m_height-1);
            
            index++;
        }
    }
   // PrintVertices();
}

void Map::CreateNormals(float* heightMap)
{
//     for (int y = 0; y < m_height; y++) {
//         for (int x = 0; x < m_width; x++) {
//             int vertexIndex = y * (m_width * 6) + x * 6;
//             CalculateNormal(vertexIndex / 6, heightMap);
//             
//             for (int i = 0; i < 3; i++) {
//                 int index = y * (m_width*6) + x * 6 + i + 3;
//                 
//                 if (index % 3 == 0)
//                     m_vertices[index] = m_normal.x;
//                 else if (index % 3 == 1)
//                     m_vertices[index] = m_normal.y;
//                 else if (index % 3 == 2)
//                     m_vertices[index] = m_normal.z;
//             }
//         }
//     }
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
    int index = 0;
    for (int y = 0; y < m_height - 1; y++) {
        for (int x = 0; x < m_width - 1; x++) {
            int topLeft = (y * m_width) + x;
            int topRight = topLeft + 1;
            int botLeft = ((y+1) * m_width) + x;
            int botRight = botLeft + 1;
            m_indices[index++] = topLeft;
            m_indices[index++] = botLeft;
            m_indices[index++] = topRight;
            m_indices[index++] = topRight;
            m_indices[index++] = botLeft;
            m_indices[index++] = botRight;
        }
    }
    //PrintIndices();
}

void Map::PrintVertices()
{
    std::cout << "Vertices :" << std::endl;
    for (int i = 0; i < m_numVertices; i++) {
        std::cout << m_vertex[i].PosX << " ; " << m_vertex[i].PosY << " ; " << m_vertex[i].PosZ <<
        " / " << m_vertex[i].NormX << " ; " << m_vertex[i].NormY << " ; " << m_vertex[i].NormZ << " / " <<
        m_vertex[i].TexCoordX << " ; " << m_vertex[i].TexCoordY << std::endl;
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







