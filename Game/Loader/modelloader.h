#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <GL/glew.h>
#include <string>

class ModelLoader
{
public:
    ModelLoader();
    ~ModelLoader();
    
    void Load(const std::string& fileName);
    const GLuint& getVaoId() const { return m_VAO; }
    const GLuint& getVboId() const { return m_VBO; }
    const GLuint& getEboId() const { return m_EBO; }
    const int& getDrawCall() const { return m_drawCall; }
    
private:
    GLuint m_VAO, m_VBO, m_EBO;
    int m_drawCall;
};

#endif // MODELLOADER_H
