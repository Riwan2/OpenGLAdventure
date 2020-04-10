#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <GL/glew.h>
#include "stb_image.h"

class Texture 
{
public:
    Texture(const std::string& fileName);
    ~Texture();
    
    const GLuint& getId() { return m_textureId; }
    
private:
    GLuint m_textureId;
};

#endif // TEXTURE_H
