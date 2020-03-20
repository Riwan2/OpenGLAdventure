#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <GL/glew.h>
#include <string.h>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shader
{
public:
    Shader(const std::string& fileName);
    ~Shader();
        
    void LoadFromFile(const std::string& fileName);
    std::string LoadShader(const std::string& fileName);
    void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    GLuint CreateShader(const std::string& text, unsigned int type);
    void Use();
private:
    GLuint m_shaderProgram;
    GLuint m_vertexShader;
    GLuint m_fragmentShader;
public:
    GLint UniformLoc(std::string name) { return glGetUniformLocation(m_shaderProgram, name.c_str()); }
    
    void SetMat4(const std::string& name, const glm::mat4& value) {
        glUniformMatrix4fv(UniformLoc(name), 1, GL_FALSE, glm::value_ptr(value)); 
    }
    void SetVec3(const std::string& name, const glm::vec3& value) { 
        glUniform3f(UniformLoc(name), value.x, value.y, value.z); 
    }
    void SetFloat(const std::string& name, const float& value) {
        glUniform1f(UniformLoc(name), value);
    }
};
    

#endif // SHADER_H
