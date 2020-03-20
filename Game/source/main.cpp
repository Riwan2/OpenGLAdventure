#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../headers/math_3d.h"
#include "../headers/shader.h"
#include "../headers/myevent.h"

#include "../headers/camera.h"
#include "../headers/map.h"

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
//     float vertices[] = {
//          0.5f, 0.5f, 0.0f,
//          0.5f, -0.5f, 0.0f,
//          -0.5f, 0.5f, 0.0f,
//          -0.5f, -0.5f, 0.0f
//     };
//     unsigned int indices[] = {
//         0, 1, 3,
//         3, 2, 0
//     };
//     std::cout << "-Indices :" << std::endl;
//     for (int i = 0; i < numIndices; i++) {
//         std::cout << _indices[i];
//         if (i % 3 == 2) std::cout << std::endl;
//         else std::cout << " ; ";
//     }
//     
//     std::cout << "-Vertices :" << std::endl;
//     for (int i = 0; i < numVerticesFloat; i++) {
//         std::cout << _vertices[i];
//         if (i % 3 == 2) std::cout << std::endl;
//         else std::cout << " ; ";
//     }
    
    Map map(1000, 1000, 0.0125f);
    
    Shader basicShader = Shader("../Shader/basicShader");

    GLuint VBO;
    GLuint VAO;
    unsigned int EBO;
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, map.GetVerticesSize(), map.GetVertices(), GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, map.GetIndicesSize(), map.GetIndices(), GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    MyEvent myEvent;
    bool isRunning = true;
    float myTime = 0;
    
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), (float)_WIDTH/(float)_HEIGHT, 0.1f, 100.0f);
    
    Camera camera;
    unsigned int deltaTime = 0;
    unsigned int lastFrame = 0;
    
    camera.SetTarget(glm::vec3((float)map.getWidth() * map.getVertexSize() / 2 - 
    map.getVertexSize() / 2, 0, (float)map.getHeight() * map.getVertexSize() / 2 - map.getVertexSize()/2));
    
    //Light 
    
    GLuint LightVAO;
    GLuint LightVBO;
    unsigned int LightEBO;
    glGenBuffers(1, &LightEBO);
    glGenVertexArrays(1, &LightVAO);
    glGenBuffers(1, &LightVBO);
    glBindVertexArray(LightVAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, LightVBO);
    float vertices[] = {
        -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 0.0f,
        -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f,
         0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -1.0f, 0.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f,
         0.5f,  0.5f, -1.0f, 0.0f, 0.0f, 0.0f,
    };
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0,
        0, 4, 5,
        5, 1, 0,
        4, 5, 6,
        6, 7, 4,
        3, 2, 6,
        6, 7, 3,
        1, 2, 6,
        6, 5, 1,
        0, 3, 7,
        7, 4, 0,
    };
    
    glBindBuffer(GL_ARRAY_BUFFER, LightVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, LightEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    Shader lightShader = Shader("../Shader/lightShader");
    glm::mat4 model = glm::mat4(1.0f);
    glm::vec3 lightPos = glm::vec3((float)map.getWidth() * map.getVertexSize() / 2 - 
    map.getVertexSize() / 2, 3.0f, (float)map.getHeight() * map.getVertexSize() / 2 - map.getVertexSize()/2);
    model = glm::translate(model, lightPos);
    //model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    //model = glm::rotate(model, glm::radians(10.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    float size = 0.75f;
    model = glm::scale(model, glm::vec3(size, size, size));
    
    glm::mat4 mapModel = glm::mat4(1.0f);
    
    glm::vec3 mapColor = glm::vec3(0.4f, 0.35f, 0.8f); //0.1f, 0.5f, 0.4f //green : 0.3f, 0.5f, 0.2f
    glm::vec3 lightColor = glm::vec3(0.9f, 0.9f, 0.8f);

    
    while(!myEvent.HasQuit()) {
        //SDL_WarpMouseInWindow(m_window, _WIDTH/2, _HEIGHT/2);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        deltaTime = SDL_GetTicks() - lastFrame;
        
        lastFrame = SDL_GetTicks();
        
        lightShader.Use();
        
        lightShader.SetMat4("projection", projection);
        lightShader.SetMat4("view", *camera.getView());
        lightShader.SetMat4("model", model);
        lightShader.SetVec3("lightColor", lightColor);

        glBindVertexArray(LightVAO);
        glDrawElements(GL_TRIANGLES, 44, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        
        //mapModel = glm::rotate(mapModel, 0.01f, glm::vec3(0.1f, 1.0f, 0.0f));
        
        basicShader.Use();
        
        myTime += 0.01f;
        //model = glm::rotate(model, 0.05f, glm::vec3(0.0f, 0.0f, 1.0f));
        

        //float green = sin(myTime) / 4.0f +    0.75f;
        //model = glm::rotate(model, glm::radians(cos(myTime) * 5), glm::vec3(0.0f, 1.0f, 0.0f));
        //float radius = 10.0f;
        //camera.setPosition(glm::vec3(cos(myTime) * radius, 0.0f, sin(myTime) * radius));
        
        basicShader.SetMat4("projection", projection);
        basicShader.SetMat4("view", *camera.getView());
        basicShader.SetVec3("myColor", mapColor);
        basicShader.SetVec3("lightColor", lightColor);
        basicShader.SetMat4("model", mapModel);
        basicShader.SetVec3("lightPos", lightPos);
        basicShader.SetFloat("lightPower", 1.5f);
        basicShader.SetFloat("time", myTime);

        
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, map.getCount(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        
        SDL_GL_SwapWindow(m_window);        
        myEvent.Update(&deltaTime, &camera);
    }
    
    return 0;
}

