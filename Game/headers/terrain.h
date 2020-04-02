#ifndef TERRAIN_H
#define TERRAIN_H

#include <glm/glm.hpp>
#include "../headers/shader.h"
#include "../headers/vaoobject.h"
#include "../headers/map.h"

class Terrain : public Map
{
public:
    Terrain(const int& width, const int& height, const float& vertexSize);
    ~Terrain();
    
private:
    float* m_heightMap;
    
    void GenerateHeigtMap();
};

#endif // TERRAIN_H
