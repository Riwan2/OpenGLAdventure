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
    
    SDL_Window* m_window = SDL_CreateWindow(_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _WIDTH, _HEIGHT, SDL_WINDOW_OPENGL);
	SDL_GLContext m_glContext = SDL_GL_CreateContext(m_window);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    GLenum res = glewInit();
    float vertices[] = {
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };
    unsigned int indices[] = {
        0, 1, 3,
        3, 2, 0
    };
    
    Shader basicShader = Shader("../Shader/basicShader");

    GLuint VBO;
    GLuint VAO;
    unsigned int EBO;
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    MyEvent myEvent;
    bool isRunning = true;
    float myTime = 0;
    
    glm::vec3 planePosition[] = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 0.0f),
        glm::vec3(3.0f, 0.5f, 1.0f),
        glm::vec3(-0.5f, 0.0f, -2.0f),
    };
        
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
    
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
    
    glm::mat4 view;
    view = glm::lookAt(cameraPos, cameraTarget, up);
    
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), (float)_WIDTH/(float)_HEIGHT, 0.1f, 100.0f);
    
    Camera camera;
    
    while(!myEvent.HasQuit()) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        basicShader.Use();
        
        myTime += 0.01f;
        //model = glm::rotate(model, 0.05f, glm::vec3(0.0f, 0.0f, 1.0f));

        //float green = sin(myTime) / 4.0f + 0.75f;
        //model = glm::rotate(model, glm::radians(cos(myTime) * 5), glm::vec3(0.0f, 1.0f, 0.0f));
        float radius = 10.0f;
        cameraPos = glm::vec3(cos(myTime) * radius, 0.0f, sin(myTime) * radius);
        view = glm::lookAt(cameraPos, cameraTarget, up);
        
        glUniformMatrix4fv(glGetUniformLocation(*basicShader.getShaderProgram(), "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(*basicShader.getShaderProgram(), "projection"), 1, GL_FALSE,glm::value_ptr(projection));
        
        glBindVertexArray(VAO);
        
        for (unsigned int i = 0; i < 4; i++) {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, planePosition[i]);
            if (i < 2) model = glm::rotate(model, cos(myTime * 2), glm::vec3(1.0f, 0.0f, 0.0f));

            glUniformMatrix4fv(glGetUniformLocation(*basicShader.getShaderProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model));
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        }
        glBindVertexArray(0);
        
        SDL_GL_SwapWindow(m_window);        
        myEvent.Update();
    }
    
    return 0;
}

