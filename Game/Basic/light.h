#ifndef LIGHT_H
#define LIGHT_H

#include "../Model/shader.h"
#include <vector>

namespace light 
{
    const int MAX_LIGHT = 4;

    struct PointLight {
        glm::vec3 position, color;
        float constant, linear, quadratic;
        PointLight(glm::vec3 col = glm::vec3(0), glm::vec3 pos = glm::vec3(0), glm::vec3 atten = glm::vec3(1.0, 0.01, 0.002)) : color(col), position(pos), constant(atten.x), linear(atten.y), quadratic(atten.z)
        {
        }
    };

    inline void Move(PointLight* light, const glm::vec3& movement) {
        light->position += movement;
    }

    inline void LoadLigthIntoShader(Shader* shader, std::vector<PointLight*> listPointLight)
    {
        for (int i = 0; i < light::MAX_LIGHT; i++) {
            if (i < listPointLight.size()) {
                PointLight* light = listPointLight[i];
                shader->SetVec3("lightColor[" + std::to_string(i) + "]", light->color);
                shader->SetVec3("lightPos[" + std::to_string(i) + "]", light->position);
                shader->SetVec3("lightAttenuation[" + std::to_string(i) + "]", glm::vec3(light->constant, light->linear, light->quadratic));
            } else {
                shader->SetVec3("lightColor[" + std::to_string(i) + "]", glm::vec3(0));
                shader->SetVec3("lightPos[" + std::to_string(i) + "]", glm::vec3(0));
                shader->SetVec3("lightAttenuation[" + std::to_string(i) + "]", glm::vec3(0));
            }
        }
    }
}

#endif // LIGHT_H
