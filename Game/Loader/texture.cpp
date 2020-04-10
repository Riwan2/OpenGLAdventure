#include "texture.h"

Texture::Texture(const std::string& fileName)
{
    int width, height, nrChannels;
    std::string myTextureFileName = "../Asset/Texture/" + fileName + ".jpg";
    unsigned char* data = stbi_load(myTextureFileName.c_str(), &width, &height, &nrChannels, 0);
    
    if (data) {
    glGenTextures(1, &m_textureId);
    glBindTexture(GL_TEXTURE_2D, m_textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "Failed to load texture : " << fileName << std::endl;
    }
    
    stbi_image_free(data);
}

Texture::~Texture()
{
}