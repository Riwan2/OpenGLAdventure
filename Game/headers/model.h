#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>
#include <GL/gl.h>

#include "../Loader/objloader.h"

#include "../Loader/stb_image.h"

class Model
{
public:
    Model();
    ~Model();
    
    void Load(const std::string& ModelFileName, const std::string& TextureFileName);
    void Render();
private:
    unsigned int m_VAO, m_VBO, m_EBO, m_Texture;
    int m_drawCall;
public:
    
};

#endif // MODEL_H
