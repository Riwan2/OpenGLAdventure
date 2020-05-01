#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>

class ModelLoader
{
public:
    ModelLoader(const std::string& fileName, const bool& instancedModel = false);
    ~ModelLoader();
    
    const GLuint& getVaoId() const { return m_VAO; }
    const GLuint& getModelId() const { return m_Model; }
    const bool& isInstanced() const { return m_instanced; }
    const int& getDrawCall() const { return m_drawCall; }
    
private:
    GLuint m_VAO, m_VBO, m_EBO, m_Model;
    bool m_instanced;
    int m_drawCall;
};

#endif // MODELLOADER_H
