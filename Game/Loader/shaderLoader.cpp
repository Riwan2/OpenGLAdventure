#include "shaderLoader.h"

ShaderLoader::ShaderLoader()
{
}

ShaderLoader::~ShaderLoader()
{
}

void ShaderLoader::Load(const std::string& fileName)
{
    m_shaderProgramId = glCreateProgram();
    m_vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    m_fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    
    std::string ShaderFileName = "../Shader/" + fileName;
    m_vertexShaderId = CreateShader(LoadShader(ShaderFileName + ".vr"), GL_VERTEX_SHADER);
	m_fragmentShaderId = CreateShader(LoadShader(ShaderFileName + ".fa"), GL_FRAGMENT_SHADER);

    glAttachShader(m_shaderProgramId, m_vertexShaderId);
    glAttachShader(m_shaderProgramId, m_fragmentShaderId);

	glLinkProgram(m_shaderProgramId);
	CheckShaderError(m_shaderProgramId, GL_LINK_STATUS, true, "Error linking shader program");

	glValidateProgram(m_shaderProgramId);
	CheckShaderError(m_shaderProgramId, GL_LINK_STATUS, true, "Invalid shader program");
}

std::string ShaderLoader::LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());
    std::string output;
    std::string line;
    if(file.is_open()) {
        while(file.good()) {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }
    return output;
}

void ShaderLoader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    char error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}

unsigned int ShaderLoader::CreateShader(const std::string& text, unsigned int type)
{
    unsigned int shader = glCreateShader(type);

    if(shader == 0)
		std::cerr << "Error compiling shader type " << type << std::endl;

    const GLchar* p[1];
    p[0] = text.c_str();
    GLint lengths[1];
    lengths[0] = text.length();

    glShaderSource(shader, 1, p, lengths);
    glCompileShader(shader);
    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!");

    return shader;
}
