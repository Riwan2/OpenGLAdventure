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
    m_texture = new Texture(copy.GetTexture());
    m_transparency = copy.GetTransparency();
}

Model::Model(ModelLoader* modelLoader, Texture* texture, const bool& transparency)
{
    //Raw Model :
    m_VAO = modelLoader->getVaoId();
    m_VBO = modelLoader->getVboId();
    m_EBO = modelLoader->getEboId();
    m_drawCall = modelLoader->getDrawCall();
    m_transparency = transparency;
    
    //Texture :
    m_texture = new Texture(*texture);
    
    delete modelLoader;
}

Model::~Model()
{
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteTextures(1, &m_texture->getId());
    delete m_texture;
}

void Model::Bind() const
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_texture->getId());
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
