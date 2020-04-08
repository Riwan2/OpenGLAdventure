#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderLoader.h"

class Shader
{
public:
    Shader(ShaderLoader& shaderLoader);
    ~Shader();
        
    void Use();
private:
    unsigned int m_shaderProgramId, m_vertexShaderId, m_fragmentShaderId;
public:
    unsigned int UniformLoc(const std::string& name) { return glGetUniformLocation(m_shaderProgramId, name.c_str()); }
    
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
