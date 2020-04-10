#include "model.h"

Model::Model()
{
}

Model::Model(const Model& copy) 
{
    m_VAO = copy.GetVAO();
    m_VBO = copy.GetVBO();
    m_EBO = copy.GetEBO();
    m_drawCall = copy.GetDrawCall();
    m_textureId = copy.GetTextureID();
}

Model::Model(ModelLoader* modelLoader, const unsigned int& TextureId)
{
    //Raw Model :
    m_VAO = modelLoader->getVaoId();
    m_VBO = modelLoader->getVboId();
    m_EBO = modelLoader->getEboId();
    m_drawCall = modelLoader->getDrawCall();
    
    //Texture :
    m_textureId = TextureId;
    
    delete modelLoader;
}

Model::~Model()
{
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteTextures(1, &m_textureId);
}

void Model::Bind() const
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_textureId);
    glBindVertexArray(m_VAO);
}

void Model::Render() const
{
    glDrawElements(GL_TRIANGLES, m_drawCall, GL_UNSIGNED_INT, 0);
}

void Model::Unbind() const
{
    glBindVertexArray(0);
    glDisable(GL_TEXTURE_2D);
}
