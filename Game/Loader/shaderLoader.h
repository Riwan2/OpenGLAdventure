#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include <GL/glew.h>

#include <string>
#include <iostream>
#include <fstream>

class ShaderLoader
{
public:
    ShaderLoader();
    ~ShaderLoader();
    
    void Load(const std::string& fileName);
    void LoadFromFile(const std::string& fileName);
    std::string LoadShader(const std::string& fileName);
    void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    unsigned int CreateShader(const std::string& text, unsigned int type);
    void Use();
    
    const GLuint& getShaderProgramId() const { return m_shaderProgramId; }
    const GLuint& getVertexShaderId() const { return m_vertexShaderId; }
    const GLuint& getFragmentShaderId() const { return m_fragmentShaderId; }

private:
    GLuint m_shaderProgramId, m_vertexShaderId, m_fragmentShaderId;
};

#endif //SHADERLOADER_H
