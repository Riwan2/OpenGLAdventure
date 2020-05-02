#include "shader.h"

Shader::Shader(const shaderLoader::ShaderObj& shaderObj)
{
    m_shaderProgramId = shaderObj.programId;
    m_vertexShaderId = shaderObj.vertexId;
    m_fragmentShaderId = shaderObj.fragmentId;
}

Shader::~Shader()
{
    glDetachShader(m_shaderProgramId, m_vertexShaderId);
    glDetachShader(m_shaderProgramId, m_fragmentShaderId);
    
    glDeleteShader(m_vertexShaderId);
    glDeleteShader(m_fragmentShaderId);
    
    glDeleteProgram(m_shaderProgramId);
}

void Shader::Use()
{
    glUseProgram(m_shaderProgramId);
}
