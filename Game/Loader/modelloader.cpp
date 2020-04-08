#include "modelloader.h"
#include "../Loader/objloader.h"

ModelLoader::ModelLoader()
{

}

ModelLoader::~ModelLoader()
{
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
    glDeleteVertexArrays(1, &m_VAO);
}

void ModelLoader::Load(const std::string& fileName)
{
    objl::Vertex* vertices;
    GLuint* indices;
    int verticesSize, indicesSize;
    
	objl::Loader Loader;
    std::string myFileName = "../Asset/Model/" + fileName + ".obj";
    Loader.LoadFile(myFileName);
    
    verticesSize = Loader.LoadedMeshes[0].Vertices.size();
    indicesSize = Loader.LoadedMeshes[0].Indices.size();
    m_drawCall = indicesSize;
    vertices = new objl::Vertex[verticesSize];
    indices = new unsigned int[indicesSize];
    
    for (int i = 0; i < verticesSize; i++) {
        vertices[i] = Loader.LoadedMeshes[0].Vertices[i];
        vertices[i].TextureCoordinate.Y = 1 - vertices[i].TextureCoordinate.Y;
    }
    for (int i = 0; i < indicesSize; i += 3)
    {
            indices[i] = Loader.LoadedMeshes[0].Indices[i];
            indices[i+1] = Loader.LoadedMeshes[0].Indices[i+1];
            indices[i+2] = Loader.LoadedMeshes[0].Indices[i+2];
    }
   
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
    
    glBindVertexArray(m_VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO); //Vertices
    glBufferData(GL_ARRAY_BUFFER, verticesSize * sizeof(objl::Vertex), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); //Triangle Indices
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0); //Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    
    glEnableVertexAttribArray(1); //Normals
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    
    glEnableVertexAttribArray(2); //Texture Position
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    
    glBindVertexArray(0);
    
    delete vertices;
    delete indices;
}

