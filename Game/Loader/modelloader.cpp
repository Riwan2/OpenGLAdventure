#include "modelloader.h"
#include "objloader.h"

ModelLoader::ModelLoader(const std::string& fileName, const bool& instancedModel)
{
    m_instanced = instancedModel;
    objl::Vertex* vertices;
    GLuint* indices;
    int verticesSize, indicesSize;
    
	objl::Loader Loader;
    std::string myFileName = "../Asset/Model/" + fileName + ".obj";
    bool loaded = Loader.LoadFile(myFileName);
    
    if (loaded) {
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

        if (instancedModel) {
            glGenBuffers(1, &m_Model);
            std::size_t vec4Size = sizeof(glm::vec4);
            glBindBuffer(GL_ARRAY_BUFFER, m_Model);
            glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4), NULL, GL_STREAM_DRAW);

            glEnableVertexAttribArray(3);
            glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)0);
            glEnableVertexAttribArray(4);
            glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(1 * vec4Size));
            glEnableVertexAttribArray(5);
            glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(2 * vec4Size));
            glEnableVertexAttribArray(6);
            glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(3 * vec4Size));

            glVertexAttribDivisor(0, 0);
            glVertexAttribDivisor(3, 1);
            glVertexAttribDivisor(4, 1);
            glVertexAttribDivisor(5, 1);
            glVertexAttribDivisor(6, 1);
        }
            
        glBindVertexArray(0);
    } else {
        std::cerr << "Failed to load model : " << fileName << std::endl;
    }
    
    delete vertices;
    delete indices;

    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
}

ModelLoader::~ModelLoader()
{
    
}
