#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../headers/shader.h"
#include "../headers/myevent.h"
#include "../headers/util.h"
#include "../headers/camera.h"
#include "../headers/map.h"
#include "../headers/light.h"

#include "../headers/terrain.h"
#include "../headers/water.h"

//Load
#define STB_IMAGE_IMPLEMENTATION

//Model
#include "../headers/model.h"

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

    Water water(50, 50, 1.0f); //200, 200, 0.5F
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
    Light light(glm::vec3(0.9f, 0.9f, 0.4f));
    //light.Move(glm::vec3(center.x, 2.0f, center.z));
    light.Move(glm::vec3(5.0, 7.0f, 0));
    
    Shader basicShader("../Shader/basicShader");
    glm::mat4 basicModel = glm::mat4(1.0f);
    camera.SetTarget(glm::vec3(0, 0, 0));
    
    Model stall;
    stall.Load("cube", "stall");
    
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
        light.Move(glm::vec3(-0.01f, -0.01f, -0.01f));
        
        basicShader.Use();
        basicShader.SetMat4("projection", projection);
        basicShader.SetMat4("view", *camera.getView());
        basicShader.SetMat4("model", basicModel);
        basicShader.SetVec3("lightColor", *light.getColor());
        basicShader.SetVec3("lightPos", *light.getPosition());
        //basicShader.SetVec3("myColor", glm::vec3(0.2, 0.7, 0.3));
        
        stall.Render();
        
        SDL_GL_SwapWindow(m_window);        
        myEvent.Update(&deltaTime, &camera);
    }
    
    return 0;
}

