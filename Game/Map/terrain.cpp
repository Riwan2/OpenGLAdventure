#include "terrain.h"
#include "../Basic/parameters.h"

Terrain::Terrain(const float& posX, const float& posZ, const float& size, const shaderLoader::ShaderObj& shaderObj, Texture* grass, Texture* path,
Texture* blendMap) : Map { posX, posZ, size }
{
    m_shader = new Shader(shaderObj);
    m_grass = new Texture(*grass);
    m_path = new Texture(*path);
    m_blendMap = new Texture(*blendMap);

    m_maxHeight = 40;
    LoadHeightMap();
    Map::Initialize(m_heightMap);

    m_model = glm::mat4(1.0f);
    m_color = glm::vec3(0.1f, 0.5f, 0.4f);

    m_shader->Use();
    m_shader->SetFloat("ambientStrength", 0.1);
    m_shader->SetFloat("density", parameters::FogDensity);
    m_shader->SetFloat("gradient", parameters::FogGradient);
}

Terrain::~Terrain()
{
    //delete m_heightMap;
    glDeleteTextures(1, &m_grass->getId());
    glDeleteTextures(1, &m_path->getId());
    glDeleteTextures(1, &m_blendMap->getId());

    delete m_grass;
    delete m_path;
    delete m_blendMap;
    delete m_shader;
    delete m_heightMap;
}

void Terrain::LoadHeightMap()
{
    std::string name = "../Asset/Texture/heightmap.png";
    int width, height, nrChannels;
    unsigned char* data = stbi_load(name.c_str(), &width, &height, &nrChannels, 1);
    unsigned int r, g, b, a;
    unsigned char* current_head = data;
    m_heightMapWidth = width;
    m_heightMapHeight = height;
    m_heightMap = new float[width * height];

    for(int z = 0; z < height; z++) {
        for(int x = 0; x < width; x++) {            
            //m_heightMap[z * width + x] = ((float)data[z * width + x] - 127.5) / 127.5 * m_maxHeight;
            unsigned int pix = current_head[0] << 16 | current_head[1] << 8 | current_head[2];
            current_head += 1;
            float height = (float)pix;
            height -= (256* 256 * 256) / 2;
            height /= (256 * 256 * 256) / 2;
            height *= m_maxHeight;
            m_heightMap[z * width + x] = height;
        }
    }

    stbi_image_free(data);
}

void Terrain::Render(const Camera* camera, const std::vector<light::PointLight*>& listPointLight)
{   
    m_shader->Use();
    m_shader->SetMat4("projection", camera->GetProjection());
    m_shader->SetMat4("view", camera->GetView());
    m_shader->SetMat4("model", m_model);
    m_shader->SetVec3("skyColor", parameters::skyColor);
    m_shader->SetInt("grass", 0);
    m_shader->SetInt("path", 1);
    m_shader->SetInt("blendMap", 2);

    light::LoadLigthIntoShader(m_shader, listPointLight);
    
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_grass->getId());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_path->getId());
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, m_blendMap->getId());

    Map::BasicRendering();
    glDisable(GL_TEXTURE_2D);
}

