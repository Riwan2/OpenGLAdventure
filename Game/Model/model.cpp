#include "model.h"
#include "../Loader/objloader.h"

Model::Model()
{
    
}

Model::~Model()
{
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
    glDeleteVertexArrays(1, &m_VAO);
    delete m_shader;
}

void Model::Move(const float& x, const float& y, const float& z)
{
    m_position += glm::vec3(x, y, z);
    m_model = glm::translate(m_model, glm::vec3(x, y , z));
}

void Model::Rotate(const float& degree, const char& axes) //only x, y and z for the axes
{
    if (degree > -360 && degree < 360) {
        switch(axes) {
            case 'x':
                m_rotation.x += degree;
                if (m_rotation.x < 0) m_rotation += 360;
                else if (m_rotation.x > 360) m_rotation -= 360;
                m_model = glm::rotate(m_model, (float)glm::radians(degree), glm::vec3(1, 0, 0));
                break;
            case 'y':
                m_rotation.y += degree;
                if (m_rotation.y < 0) m_rotation += 360;
                else if (m_rotation.y > 360) m_rotation -= 360;
                m_model = glm::rotate(m_model, (float)glm::radians(degree), glm::vec3(0, 1, 0));
                break;
            case 'z':
                m_rotation.z += degree;
                if (m_rotation.z < 0) m_rotation += 360;
                else if (m_rotation.z > 360) m_rotation -= 360;
                m_model = glm::rotate(m_model, (float)glm::radians(degree), glm::vec3(0, 0, 1));
                break;
        }
    }
}

void Model::Render(const glm::mat4& CameraProjection, const glm::mat4& cameraView, const glm::vec3& lightPos, const glm::vec3& lightColor)
{
    m_shader->Use();
    m_shader->SetMat4("projection", CameraProjection);
    m_shader->SetMat4("view", cameraView);
    m_shader->SetMat4("model", m_model);
    m_shader->SetVec3("lightPos", lightPos);
    m_shader->SetVec3("lightColor", lightColor);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_drawCall, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glDisable(GL_TEXTURE_2D);
}

void Model::Load(const std::string& ModelFileName, const unsigned int& TextureId, ShaderLoader& shaderLoader)
{
    //Raw Model :
    objl::Vertex* vertices;
    unsigned int* indices;
    int verticesSize, indicesSize;
    
	objl::Loader Loader;
    Loader.LoadFile("../Asset/Model/cube.obj");
    
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
    
    //Texture :
    m_Texture = TextureId;
    
    //Shader:
    m_shader = new Shader(shaderLoader);
    m_model = glm::mat4(1.0);
    m_position = glm::vec3(0.0, 0.0, 0.0);
    m_rotation = glm::vec3(0.0, 0.0, 0.0);
}
