#include "water.h"

Water::Water(const float& posX, const float& posZ, const float& size, const shld::ShaderObj& shaderObj, txtl::Texture2d* texture, txtl::Texture2d* displacementMap) 
: Map { posX, posZ, size }
{
    FlatHeightMap();
    Initialize(m_heightMap);
    m_shader = new Shader(shaderObj);
    m_texture = new txtl::Texture2d(*texture);
    m_displacementMap = new txtl::Texture2d(*displacementMap);
    
    m_model = glm::mat4(1.0f);
    m_model = glm::translate(m_model, glm::vec3(0.0, -6.0, 0.0));
    m_time = 0;
}

Water::~Water()
{
    delete m_texture;
    delete m_displacementMap;
}

void Water::Render(const Camera* camera)
{
    m_time += 0.01f;
    m_shader->Use();
    
    m_shader->SetMat4("projection", camera->GetProjection());
    m_shader->SetMat4("view", camera->GetView());
    m_shader->SetMat4("model", m_model);
    m_shader->SetFloat("time", m_time);
    m_shader->SetInt("myTexture1", 0);
    m_shader->SetInt("displacementMap", 1);

    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture->textureId);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_displacementMap->textureId);

    Map::BasicRendering();
    glDisable(GL_TEXTURE_2D);
}

void Water::FlatHeightMap()
{
    int width = 64;
    m_heightMapWidth = width;
    m_heightMapHeight = width;
    m_heightMap = new float[width*width];

    for (int i = 0; i < width * width; i++) {
        m_heightMap[i] = 0.0f;
    }
}


