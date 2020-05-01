#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <GL/glew.h>
#include "stb_image.h"
#include "glm/glm.hpp"

class Texture 
{
public:
    Texture(const std::string& fileName, const float& reflectivity = 0.0, const float& shineDamper = 64, const int& rowNumber = 1, const bool& png = false);
    ~Texture();
    
    const GLuint& getId() const { return m_textureId; }
    const float& getReflectivity() const { return m_reflectivity; }
    const float& getShineDamper() const { return m_shineDamper; }
    const int& getNumRow() const { return m_rowNumber; }
    const glm::vec2 getOffset(const int& index) const;
private:
    float m_reflectivity, m_shineDamper, m_textureWidth, m_textureHeight;
    int m_rowNumber;
    GLuint m_textureId;
};

#endif // TEXTURE_H
