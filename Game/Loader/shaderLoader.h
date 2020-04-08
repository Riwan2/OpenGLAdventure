#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <string.h>
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
    
    const unsigned int& getShaderProgramId() { return m_shaderProgramId; }
    const unsigned int& getVertexShaderId() { return m_vertexShaderId; }
    const unsigned int& getFragmentShaderId() { return m_fragmentShaderId; }

private:
    unsigned int m_shaderProgramId, m_vertexShaderId, m_fragmentShaderId;
};

#endif //SHADERLOADER_H
