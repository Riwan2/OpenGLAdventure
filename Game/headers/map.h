#ifndef MAP_H
#define MAP_H

class Map
{
public:
    Map(const int& width, const int& height, const float& vertexSize);
    ~Map();
    
    float* GetVertices() { return m_vertices; }
    int GetVerticesSize() { return m_numVertices * 3 * sizeof(float); }

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
    
    float* m_vertices;
    unsigned int* m_indices;
    
    void CreateVertices();
    void CreateIndices();
};

#endif // MAP_H
