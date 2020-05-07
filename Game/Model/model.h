#ifndef MODEL_H
#define MODEL_H

#include "../Loader/texture.h"
#include <bits/stdc++.h> 

class Model
{
public:
    Model();
    Model(const Model& copy);
    Model(const std::string& fileName, txtl::Texture2d* texture, const bool& instanced = false, const bool& culling = false);
    ~Model();
    
    void Bind() const;
    void Render() const;
    void Render(const glm::mat4* modelMatrices, const int& numInstance) const;
    void Unbind() const;
    
private:
    GLuint m_VAO, m_Model;
    int m_drawCall;
    txtl::Texture2d* m_texture;
    bool m_culling, m_instanced;
    
public:
    const GLuint& GetVAO() const { return m_VAO; }
    const GLuint& GetModelId() const { return m_Model; }
    txtl::Texture2d& GetTexture() const { return *m_texture; }
    const int& GetDrawCall() const { return m_drawCall; }
    const bool& GetCulling() const { return m_culling; }
    const bool& isInstanced() const { return m_instanced; }
};

class ModelHashFunction { 
public:
    
    size_t operator()(const Model* m) const
    { 
        return m->GetVAO() + m->GetTexture().textureId + m->GetDrawCall();
    } 
}; 

#endif // MODEL_H
