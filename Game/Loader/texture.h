#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <string>

#include "stb_image.h"

class Texture 
{
public:
    Texture();
    ~Texture();
    
    void Load(const std::string& fileName);
    const GLuint& getId() { return m_textureId; }
    
private:
    GLuint m_textureId;
};

#endif // TEXTURE_H
