#ifndef MODEL_H
#define MODEL_H

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Loader/modelloader.h"
#include <bits/stdc++.h> 

class Model
{
public:
    Model();
    Model(const Model& copy);
    Model(ModelLoader* modelLoader, const unsigned int& TextureId);
    ~Model();
    
    void Bind() const;
    void Render() const;
    void Unbind() const;
    
private:
    GLuint m_VAO, m_VBO, m_EBO, m_textureId;
    int m_drawCall;
    
public:
    const GLuint& GetVAO() const { return m_VAO; }
    const GLuint& GetVBO() const { return m_VBO; }
    const GLuint& GetEBO() const { return m_EBO; }
    const GLuint& GetTextureID() const { return m_textureId; }
    const int& GetDrawCall() const { return m_drawCall; }
};

class ModelHashFunction { 
public:
    
    size_t operator()(const Model& m) const
    { 
        return m.GetVAO() + m.GetVBO() + m.GetEBO() + m.GetTextureID() + m.GetDrawCall();
    } 
}; 

#endif // MODEL_H
