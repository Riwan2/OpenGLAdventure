#include "../headers/terrain.h"
#include "../headers/util.h"

Terrain::Terrain(const int& width, const int& height, const float& vertexSize) 
: Map { width, height, vertexSize }
{
    GenerateHeigtMap();
    
    Initialize(m_heightMap);
}

Terrain::~Terrain()
{

}

void Terrain::GenerateHeigtMap()
{
    m_heightMap = new float[GetNumVertices()];
    
    for (int i = 0; i < GetNumVertices(); i++) {
        m_heightMap[i] = 0;//float(Util::getInt(10)) / 150;
    }
}

