#include "texture.h"

Texture::Texture(const std::string& fileName, const float& reflectivity, const float& shineDamper, const bool& png)
{
    m_reflectivity = reflectivity;
    m_shineDamper = shineDamper;
    
    int width, height, nrChannels;
    std::string myTextureFileName;
    if (png) myTextureFileName = "../Asset/Texture/" + fileName + ".png";
    else myTextureFileName = "../Asset/Texture/" + fileName + ".jpg";
    unsigned char* data = stbi_load(myTextureFileName.c_str(), &width, &height, &nrChannels, 0);
    
    if (data) {
        glGenTextures(1, &m_textureId);
        glBindTexture(GL_TEXTURE_2D, m_textureId);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        
        if (png) glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        else glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "Failed to load texture : " << fileName << std::endl;
    }
    
    stbi_image_free(data);
}

Texture::~Texture()
{
}
