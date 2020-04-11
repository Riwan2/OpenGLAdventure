#ifndef MODEL_H
#define MODEL_H

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Loader/modelloader.h"
#include "../Loader/texture.h"
#include <bits/stdc++.h> 

class Model
{
public:
    Model();
    Model(const Model& copy);
    Model(ModelLoader* modelLoader, Texture* texture, const bool& transparency = false);
    ~Model();
    
    void Bind() const;
    void Render() const;
    void Unbind() const;
    
private:
    GLuint m_VAO, m_VBO, m_EBO;
    int m_drawCall;
    Texture* m_texture;
    bool m_transparency;
    
public:
    const GLuint& GetVAO() const { return m_VAO; }
    const GLuint& GetVBO() const { return m_VBO; }
    const GLuint& GetEBO() const { return m_EBO; }
    Texture& GetTexture() const { return *m_texture; }
    const int& GetDrawCall() const { return m_drawCall; }
    const bool& GetTransparency() const { return m_transparency; }
};

class ModelHashFunction { 
public:
    
    size_t operator()(const Model* m) const
    { 
        return m->GetVAO() + m->GetVBO() + m->GetEBO() + m->GetTexture().getId() + m->GetDrawCall();
    } 
}; 

#endif // MODEL_H
