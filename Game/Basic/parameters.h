#ifndef PARAMETERS_H
#define PARAMATERS_H

#include <glm/glm.hpp>

namespace parameters {
    static const char* Title = "coucou";
    static const int PosX = 100;
    static const int PosY = 100;
    static int Width = 1150;
    static int Height = 640;
    static glm::vec3 skyColor = glm::vec3(0.03, 0.1, 0.1); //0.23, 0.65, 0.68
    static float FogDensity = 0.003; //0.003 -> distance of the fog
    static float FogGradient = 2.5; //2.5 -> how smooth the fog is
}

#endif
