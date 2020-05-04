#include "skybox.h"
#include "../Basic/parameters.h"

Skybox::Skybox(const shld::ShaderObj& shaderObj, const std::vector<std::string> facesFileName, const float& size)
{
	m_vaoObject = vaoLoader::LoadSkyBox(size);
	m_shader = new Shader(shaderObj);
	m_textureId = txtl::LoadCubemapTexture(facesFileName);
}

Skybox::~Skybox()
{
	delete m_shader;
}

void Skybox::Render(const Camera& camera, const glm::vec3& playerPos)
{
    glEnable(GL_CULL_FACE);
    glDepthMask(GL_FALSE);
    //glDepthRange(1.0, 1.0);
    m_shader->Use();
    m_shader->SetMat4("projection", camera.GetProjection());
    glm::mat4 view = glm::mat4(glm::mat3(camera.GetView()));
    static float rotation = 0;
    rotation += 0.02;
    view = glm::rotate(view, glm::radians(rotation), glm::vec3(0, 1, 0));
    view = glm::rotate(view, -glm::radians(rotation), glm::vec3(0, 0, 1));
    m_shader->SetMat4("view", view);
    m_shader->SetVec3("fogColor", parameters::skyColor);

    glBindVertexArray(m_vaoObject.vaoId);
    glEnableVertexAttribArray(0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureId);
    glDrawArrays(GL_TRIANGLES, 0, m_vaoObject.drawCall);
    glBindVertexArray(0);
    //glDepthRange(0.0, 1.0);
    glDepthMask(GL_TRUE);
    glDisable(GL_CULL_FACE);
}