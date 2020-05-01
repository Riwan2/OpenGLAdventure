#include "model.h"

Model::Model()
{
}

Model::Model(const Model& copy) 
{
    m_instanced = copy.isInstanced();
    if (m_instanced) m_Model = copy.GetModelId();
    m_VAO = copy.GetVAO();
    m_drawCall = copy.GetDrawCall();
    m_texture = new Texture(copy.GetTexture());
    m_transparency = copy.GetTransparency();
}

Model::Model(ModelLoader* modelLoader, Texture* texture, const bool& transparency)
{
    //Raw Model :
    m_instanced = modelLoader->isInstanced();
    if (m_instanced) m_Model = modelLoader->getModelId();
    m_VAO = modelLoader->getVaoId();
    m_drawCall = modelLoader->getDrawCall();
    m_transparency = transparency;
    
    //Texture :
    m_texture = new Texture(*texture);

    delete modelLoader;
}

Model::~Model()
{
    glDeleteVertexArrays(1, &m_VAO);
    if (m_instanced) glDeleteBuffers(1, &m_Model);
    glDeleteTextures(1, &m_texture->getId());
    delete m_texture;
}

void Model::Bind() const
{
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture->getId());
    glBindVertexArray(m_VAO);
}

void Model::Render() const
{
    glDrawElements(GL_TRIANGLES, m_drawCall, GL_UNSIGNED_INT, 0);
}

void Model::Render(const glm::mat4* modelMatrices, const int& numInstance) const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_Model);
    glBufferData(GL_ARRAY_BUFFER, numInstance * sizeof(glm::mat4), NULL, GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, numInstance * sizeof(glm::mat4), modelMatrices);

    glDrawElementsInstanced(GL_TRIANGLES, m_drawCall, GL_UNSIGNED_INT, 0, numInstance);
}

void Model::Unbind() const
{
    glBindVertexArray(0);
    glDisable(GL_TEXTURE_2D);
}
