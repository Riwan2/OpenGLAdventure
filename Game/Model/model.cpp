#include "model.h"

Model::Model()
{
    
}

Model::~Model()
{
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

void Model::Load(const ModelLoader& modelLoader, const unsigned int& TextureId, const ShaderLoader& shaderLoader)
{
    //Raw Model :
    m_VAO = modelLoader.getVaoId();
    m_VBO = modelLoader.getVboId();
    m_EBO = modelLoader.getEboId();
    m_drawCall = modelLoader.getDrawCall();
    
    //Texture :
    m_Texture = TextureId;
    
    //Shader:
    m_shader = new Shader(shaderLoader);
    m_model = glm::mat4(1.0);
    m_position = glm::vec3(0.0, 0.0, 0.0);
    m_rotation = glm::vec3(0.0, 0.0, 0.0);
}
