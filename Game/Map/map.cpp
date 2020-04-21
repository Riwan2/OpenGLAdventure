#include "map.h"

Map::Map(const float& posX, const float& posZ, const float& size)
{
    m_size = size;
    m_posX = posX * size;
    m_posZ = posZ * size;
}

Map::~Map()
{   
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
    glDeleteVertexArrays(1, &m_VAO);
}

void Map::Initialize(float* heightMap)
{
    m_width = m_heightMapWidth;
    m_height = m_heightMapHeight;
    m_verticesSize = (float)(m_size / (m_width-1));
    m_numVertices = m_width * m_height;
    m_numIndices = (m_width-1) * (m_height-1) * 6;
    
    m_vertex = new basic::Vertex[m_numVertices];
    m_indices = new unsigned int[m_numIndices];

    CreateVertices(heightMap);
    CreateIndices();

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
    
    glBindVertexArray(m_VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO); //Vertices
    glBufferData(GL_ARRAY_BUFFER, m_numVertices * sizeof(basic::Vertex) + 8, m_vertex, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); //Triangle Indices
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_numIndices * sizeof(unsigned int), m_indices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0); //Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(1); //Normals
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    
    glEnableVertexAttribArray(2); //Texture Position
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        
    glBindVertexArray(0);

    delete m_indices;
    delete m_vertex;
}

void Map::BasicRendering() 
{
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_numIndices, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Map::CreateVertices(float* heightMap)
{
    int index = 0;
    for (int z = 0; z < m_height; z++) {
        for (int x = 0; x < m_width; x++) {
            m_vertex[z * m_width + x].PosX = m_posX + (float)x / (float)(m_width-1) * m_size;
            m_vertex[z * m_width + x].PosY = GetHeight(x, z);
            m_vertex[z * m_width + x].PosZ = m_posZ + (float)z / (float)(m_height-1) * m_size;
            glm::vec3 normal = CalculateNormal(x, z, heightMap);
            m_vertex[z * m_width + x].NormX = normal.x;
            m_vertex[z * m_width + x].NormY = normal.y;
            m_vertex[z * m_width + x].NormZ = normal.z;
            m_vertex[z * m_width + x].TexCoordX = (float)x / (float)(m_width-1);
            m_vertex[z * m_width + x].TexCoordY = (float)z / (float)(m_height-1);
        }
    }
   // PrintVertices();
}

float Map::GetHeight(const int& x, const int& z)
{
    if (x < 0 || x > m_heightMapWidth-1 || z < 0 || z > m_heightMapHeight-1)
        return 0;
    return m_heightMap[z * m_width + x];
}

float Map::GetMapHeight(const float &worldX, const float &worldZ)
{
    float terrainX = worldX - m_posX;
    float terrainZ = worldZ - m_posZ;
    int GridX = floor(terrainX / m_verticesSize);
    int GridZ = floor(terrainZ / m_verticesSize);
    float xCoord = fmod(terrainX, m_verticesSize) / m_verticesSize;
    float zCoord = fmod(terrainZ, m_verticesSize) / m_verticesSize;
    
    if (xCoord <= 1 - zCoord) { //Top Left triangle     
        return barryCentric(glm::vec3(0, GetHeight(GridX, GridZ), 0),
            glm::vec3(1, GetHeight(GridX+1, GridZ), 0),
            glm::vec3(0, GetHeight(GridX, GridZ+1), 1),
            glm::vec2(xCoord, zCoord));
    } else { //Bottom Right triangle
        return barryCentric(glm::vec3(1, GetHeight(GridX+1, GridZ), 0),
            glm::vec3(0, GetHeight(GridX, GridZ+1), 1),
            glm::vec3(1, GetHeight(GridX+1, GridZ+1), 1),
            glm::vec2(xCoord, zCoord));
    }
    return 0;
}

float Map::barryCentric(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec2 pos)
{
    float det = (p2.z - p3.z) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.z - p3.z);
    float l1 = ((p2.z - p3.z) * (pos.x - p3.x) + (p3.x - p2.x) * (pos.y - p3.z)) / det;
    float l2 = ((p3.z - p1.z) * (pos.x - p3.x) + (p1.x - p3.x) * (pos.y - p3.z)) / det;
    float l3 = 1.0f - l1 - l2;
    return l1 * p1.y + l2 * p2.y + l3 * p3.y;
}

glm::vec3 Map::CalculateNormal(const int& x, const int& z, float* heightMap)
{
    float v1, v2, v3, v4;
    if (x > 0 && x < m_heightMapWidth-1 && z > 0 && z < m_heightMapHeight - 1) {
        v1 = GetHeight(x - 1, z);
        v2 = GetHeight(x + 1, z);
        v3 = GetHeight(x, z - 1);
        v4 = GetHeight(x, z + 1);
        return glm::normalize(glm::vec3(v1 - v2, 2.0, v3 - v4));
    } 
    return glm::vec3(0.0f, 1.0f, 0.0f);
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







