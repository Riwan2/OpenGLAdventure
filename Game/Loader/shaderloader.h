    #ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>

namespace shld
{
    struct ShaderObj {
        GLuint programId, vertexId, fragmentId;
        ShaderObj()
        {}
        ShaderObj(GLuint pId, GLuint vId, GLuint fId) : programId(pId), vertexId(vId), fragmentId(fId)
        {}
        ShaderObj(const ShaderObj& obj) : programId(obj.programId), vertexId(obj.vertexId), fragmentId(obj.fragmentId)
        {}
    };

    inline ShaderObj Load(const std::string& fileName);
    inline std::string LoadShader(const std::string& fileName);
    inline void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage, const std::string& filename);
    inline unsigned int CreateShader(const std::string& text, unsigned int type, const std::string& filename);

    inline ShaderObj Load(const std::string& fileName)
    {
        GLuint programId, vertexId, fragmentId;
        programId = glCreateProgram();
        vertexId = glCreateShader(GL_VERTEX_SHADER);
        fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
        
        std::string ShaderFileName = "../Shader/" + fileName;
        vertexId = CreateShader(LoadShader(ShaderFileName + ".vr"), GL_VERTEX_SHADER, fileName);
        fragmentId = CreateShader(LoadShader(ShaderFileName + ".fa"), GL_FRAGMENT_SHADER, fileName);

        glAttachShader(programId, vertexId);
        glAttachShader(programId, fragmentId);

        glLinkProgram(programId);
        CheckShaderError(programId, GL_LINK_STATUS, true, "Error linking shader program", fileName);

        glValidateProgram(programId);
        CheckShaderError(programId, GL_LINK_STATUS, true, "Invalid shader program", fileName);
        return ShaderObj(programId, vertexId, fragmentId);
    }

    inline std::string LoadShader(const std::string& fileName)
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

    inline void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage, const std::string& filename)
    {
        GLint success = 0;
        char error[1024] = { 0 };

        if(isProgram) glGetProgramiv(shader, flag, &success);
        else glGetShaderiv(shader, flag, &success);

        if(success == GL_FALSE)
        {
            if(isProgram) glGetProgramInfoLog(shader, sizeof(error), NULL, error);
            else glGetShaderInfoLog(shader, sizeof(error), NULL, error);

            std::cerr << "In shader " << filename << " : " << errorMessage << ": '" << error << "'" << std::endl;
        }
    }

    inline unsigned int CreateShader(const std::string& text, unsigned int type, const std::string& filename)
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
        CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!", filename);

        return shader;
    }

    inline GLuint UniformLoc(const ShaderObj& shader, const std::string& name) 
    { 
        return glGetUniformLocation(shader.programId, name.c_str()); 
    }
    
    inline void SetMat4(const ShaderObj& shader, const std::string& name, const glm::mat4& value) 
    {
        glUniformMatrix4fv(UniformLoc(shader, name), 1, GL_FALSE, glm::value_ptr(value)); 
    }

    inline void SetVec2(const ShaderObj& shader, const std::string& name, const glm::vec2 value) 
    {
        glUniform2f(UniformLoc(shader, name), value.x, value.y);
    }

    inline void SetVec3(const ShaderObj& shader, const std::string& name, const glm::vec3& value) 
    { 
        glUniform3f(UniformLoc(shader, name), value.x, value.y, value.z); 
    }

    inline void SetFloat(const ShaderObj& shader, const std::string& name, const float& value) 
    {
        glUniform1f(UniformLoc(shader, name), value);
    }

    inline void SetInt(const ShaderObj& shader, const std::string& name, const int& value) 
    {
        glUniform1i(UniformLoc(shader, name), value);
    }
}

#endif //SHADERLOADER_H