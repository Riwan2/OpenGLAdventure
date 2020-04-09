#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Basic/myevent.h"
#include "../Basic/camera.h"
#include "../headers/light.h"

#define STB_IMAGE_IMPLEMENTATION

#include "../Map/terrain.h"
#include "../Map/water.h"

#include "../Loader/texture.h"
#include "../Loader/shaderLoader.h"
#include "../Loader/modelloader.h"

//Model
#include "../Model/model.h"

const char* _TITLE = "coucou";
const int _WIDTH = 850;
const int _HEIGHT = 540;
const int _POSX = 100;
const int _POSY = 100;

int main(int argc, char **argv)
{    
    SDL_Init(SDL_INIT_EVERYTHING);

    //VERSION
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    
    //BUFFER AND COLOR
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    
    //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    //glEnable(GL_MULTISAMPLE);
    
    Util::InitRandom();
    SDL_Window* m_window = SDL_CreateWindow(_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _WIDTH, _HEIGHT, SDL_WINDOW_OPENGL);
	SDL_GLContext m_glContext = SDL_GL_CreateContext(m_window);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    
    SDL_WarpMouseInWindow(m_window, _WIDTH/2, _HEIGHT/2);
    //SDL_SetWindowGrab(m_window, SDL_TRUE);
    //SDL_ShowCursor(0);
    
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
    
    GLenum res = glewInit();
    
    ShaderLoader waterShader;
    waterShader.Load("waterShader");

    Water water(50, 50, 1.0f, waterShader); //200, 200, 0.5F
    //Terrain terrain(50, 50, 1.0f);
    
    MyEvent myEvent;
    bool isRunning = true;
    float myTime = 0;
    
    glm::mat4 projection;
    
    projection = glm::perspective(glm::radians(45.0f), (float)_WIDTH/(float)_HEIGHT, 0.1f, 100.0f);
    
    Camera camera;
    unsigned int deltaTime = 0;
    unsigned int lastFrame = 0;
    
    glm::vec3 center = glm::vec3((float)water.getWidth() * water.getVertexSize() / 2 - 
    water.getVertexSize() / 2, 20.0f, (float)water.getHeight() * water.getVertexSize() / 2 - water.getVertexSize()/2);
    camera.SetTarget(center);
    
    //Light
    ShaderLoader lightShader;
    lightShader.Load("lightShader");
    
    glm::vec3 lightColor = glm::vec3(0.9f, 0.9f, 0.4f);
    Light light(lightColor, lightShader);
    //light.Move(glm::vec3(center.x, 2.0f, center.z));
    light.Move(glm::vec3(-10, 10, 10.0));
    
    camera.SetTarget(glm::vec3(0, 0, 0));
    
    Texture myTexture;
    myTexture.Load("white");
    
    ShaderLoader basicShader;
    basicShader.Load("basicShader");
    
    ModelLoader myModel;
    myModel.Load("dragon");
    
    Model stall;
    stall.Load(myModel, myTexture.getId(), basicShader);
    
    while(!myEvent.HasQuit()) {
        //SDL_WarpMouseInWindow(m_window, _WIDTH/2, _HEIGHT/2);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        deltaTime = SDL_GetTicks() - lastFrame;
        lastFrame = SDL_GetTicks();
        
        //Light
        light.Render(projection, *camera.getView());
        //Water
        //water.Render(projection, *camera.getView(), *light.getColor(), *light.getPosition());
        //Terrain
        //terrain.Render(projection, *camera.getView(), *light.getColor(), *light.getPosition());
        //light.Move(glm::vec3(-0.001, -0.001, -0.001));
        
        stall.Render(projection, *camera.getView(), *light.getPosition(), *light.getColor());
        stall.Rotate(0.25f, 'y');
        
        SDL_GL_SwapWindow(m_window);        
        myEvent.Update(&deltaTime, &camera);
    }
    
    return 0;
}

