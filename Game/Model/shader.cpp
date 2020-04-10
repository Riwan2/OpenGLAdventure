#include "shader.h"

Shader::Shader(const ShaderLoader& shaderLoader)
{
    m_shaderProgramId = shaderLoader.getShaderProgramId();
    m_vertexShaderId = shaderLoader.getVertexShaderId();
    m_fragmentShaderId = shaderLoader.getFragmentShaderId();
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
