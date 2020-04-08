#include "shader.h"

Shader::Shader(ShaderLoader& shaderLoader)
{
    m_shaderProgramId = shaderLoader.getShaderProgramId();
    m_vertexShaderId = shaderLoader.getVertexShaderId();
    m_fragmentShaderId = shaderLoader.getFragmentShaderId();
}

Shader::~Shader()
{
    
}

void Shader::Use()
{
    glUseProgram(m_shaderProgramId);
}
