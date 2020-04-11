#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <SDL2/SDL.h>

#include "../Basic/parameters.h"
#include "../Basic/myevent.h"
#include "../Basic/camera.h"

#define STB_IMAGE_IMPLEMENTATION

#include "../Renderer/renderer.h"

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
    SDL_Window* m_window = SDL_CreateWindow(parameters::Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, parameters::Width, parameters::Height, SDL_WINDOW_OPENGL);
    SDL_GLContext m_glContext = SDL_GL_CreateContext(m_window);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    SDL_WarpMouseInWindow(m_window, parameters::Width/2, parameters::Height/2);
    //SDL_SetWindowGrab(m_window, SDL_TRUE);
    //SDL_ShowCursor(0);
    
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);    
    GLenum res = glewInit();
    
    MyEvent myEvent;
    bool isRunning = true;
    float myTime = 0;
    
    Camera camera(30);
    unsigned int deltaTime = 0;
    unsigned int lastFrame = 0;
    
    Renderer renderer;
    renderer.Load(camera.GetProjection());
    
    while(!myEvent.HasQuit()) {
        //SDL_WarpMouseInWindow(m_window, _WIDTH/2, _HEIGHT/2);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        deltaTime = SDL_GetTicks() - lastFrame;
        lastFrame = SDL_GetTicks();
        
        myEvent.Update(&deltaTime, &camera);
        renderer.Render(camera);
        //Water
        //water.Render(projection, camera.getView(), light.getColor(), light.getPosition());
        //Terrain
        //terrain.Render(projection, *camera.getView(), *light.getColor(), *light.getPosition());
        //light.Move(glm::vec3(-0.001, -0.001, -0.001));
        SDL_GL_SwapWindow(m_window);        
    }
    
    return 0;
}

