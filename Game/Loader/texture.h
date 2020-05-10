#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <GL/glew.h>
#include "stb_image.h"
#include "glm/glm.hpp"
#include <vector>

namespace txtl
{
    //2D TEXTURE
    struct Texture2d {
        GLuint textureId;
        int rowNumber, width, height;
        float reflectivity, shineDamper;
        Texture2d() 
        {
        }
        Texture2d(const Texture2d& t) : textureId(t.textureId), width(t.width), height(t.height), reflectivity(t.reflectivity), shineDamper(t.shineDamper), rowNumber(t.rowNumber)
        {
        }
        Texture2d(GLuint tId, int w, int h, float refl, float shin, int rowNb) : textureId(tId), width(w), height(h), reflectivity(refl), shineDamper(shin), rowNumber(rowNb)
        {
        }
    };

    inline GLuint Load2dTexture(const std::string& fileName, unsigned char* data, int& width, int& height, int& nrChannels, const bool& png);
    inline Texture2d Load2dJPGTexture(const std::string& fileName, const float& reflectivity = 0, const float& shineDamper = 64, const int& rowNumber = 1);
    inline Texture2d Load2dPNGTexture(const std::string& fileName, const float& reflectivity = 0, const float& shineDamper = 64, const int& rowNumber = 1);
    inline glm::vec2 OffsetByIndex(const int& index, const int& rowNumber);

    //2D TEXTURE PNG AND JPG
    inline Texture2d Load2dJPGTexture(const std::string& fileName, const float& reflectivity, const float& shineDamper, const int& rowNumber)
    {   
        int width, height, nrChannels;
        std::string myTextureFileName = "../Asset/Texture/" + fileName + ".jpg";
        unsigned char* data = stbi_load(myTextureFileName.c_str(), &width, &height, &nrChannels, 0);
        GLuint textureId = Load2dTexture(fileName, data, width, height, nrChannels, false);
        return Texture2d(textureId, width, height, reflectivity, shineDamper, rowNumber);
    }

    inline Texture2d Load2dPNGTexture(const std::string& fileName, const float& reflectivity, const float& shineDamper, const int& rowNumber)
    {   
        int width, height, nrChannels;
        std::string myTextureFileName = "../Asset/Texture/" + fileName + ".png";
        unsigned char* data = stbi_load(myTextureFileName.c_str(), &width, &height, &nrChannels, 0);
        GLuint textureId = Load2dTexture(fileName, data, width, height, nrChannels, true);
        return Texture2d(textureId, width, height, reflectivity, shineDamper, rowNumber);
    }

    //2D TEXTURE BASE
    inline GLuint Load2dTexture(const std::string& fileName, unsigned char* data, int& width, int& height, int& nrChannels, const bool& png) 
    {
        GLuint textureId;
        if (data) {
            glGenTextures(1, &textureId);
            glBindTexture(GL_TEXTURE_2D, textureId);
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
        return textureId;
    }

    inline glm::vec2 OffsetByIndex(const int& index, const int& rowNumber)
    {
        float offsetX = (float)(index % rowNumber) / rowNumber;
        float offsetY = (float)floor(index / rowNumber) / rowNumber;
        return glm::vec2(offsetX, offsetY);
    }

    //CUBEMAP TEXTURE
    //In this order : right, left, top, bottom, front, back
    inline GLuint LoadCubemapTexture(const std::vector<std::string>& facesFileName) //Accept only 6 faces
    {
        int width, height, nrChannels;
        GLuint textureId;
        glGenTextures(1, &textureId);

        glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        if (facesFileName.size() != 6) {
            std::cerr << "problem when loading cubmeMap texture : texture number not equal to 6" << std::endl;
            return 0;
        }

        for (int i = 0; i < 6; i++) {
            std::string fileName = "../Asset/Texture/Cubemap/" + facesFileName[i] + ".png";
            unsigned char* data = stbi_load(fileName.c_str(), &width, &height, &nrChannels, 0);
            if (data) {
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
                stbi_image_free(data);
            } else {
                std::cerr << "Failed to load texture : " << fileName << std::endl;
            }
        }
        return textureId;
    }
}

#endif // TEXTURE_H
