#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <string>

#include "../Loader/stb_image.h"

class Texture 
{
public:
    Texture();
    ~Texture();
    
    void Load(const std::string& fileName);
    const unsigned int& getId() { return m_textureId; }
    
private:
    unsigned int m_textureId;
};

#endif // TEXTURE_H
