#include "model.h"
#include "../Loader/modelloader.h"

Model::Model()
{
}

Model::Model(const Model& copy) 
{
    m_instanced = copy.isInstanced();
    if (m_instanced) m_Model = copy.GetModelId();
    m_VAO = copy.GetVAO();
    m_drawCall = copy.GetDrawCall();
    m_texture = new txtl::Texture2d(copy.GetTexture());
    m_transparency = copy.GetTransparency();
}

Model::Model(const std::string& fileName, txtl::Texture2d* texture, const bool& instanced, const bool& transparency)
{
    //Raw Model :
    m_instanced = instanced;

    vaoLoader::VaoObject myVao;
    if (m_instanced) myVao = vaoLoader::LoadInstancedObj(fileName);
    else myVao = vaoLoader::LoadBasicObj(fileName);

    if (m_instanced) m_Model = myVao.modelId;
    m_VAO = myVao.vaoId;
    m_drawCall = myVao.drawCall;
    m_transparency = transparency;
    
    //Texture :
    m_texture = new txtl::Texture2d(*texture);
}

Model::~Model()
{
    glDeleteVertexArrays(1, &m_VAO);
    if (m_instanced) glDeleteBuffers(1, &m_Model);
    glDeleteTextures(1, &m_texture->textureId);
    delete m_texture;
}

void Model::Bind() const
{
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture->textureId);
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
