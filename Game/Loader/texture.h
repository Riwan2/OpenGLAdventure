#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <GL/glew.h>
#include "stb_image.h"

class Texture 
{
public:
    Texture(const std::string& fileName, const float& reflectivity, const float& shineDamper, const bool& png = false);
    ~Texture();
    
    const GLuint& getId() const { return m_textureId; }
    const float& getReflectivity() const { return m_reflectivity; }
    const float& getShineDamper() const { return m_shineDamper; }
    
private:
    float m_reflectivity, m_shineDamper;
    GLuint m_textureId;
};

#endif // TEXTURE_H
