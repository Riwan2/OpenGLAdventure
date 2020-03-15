#include "../headers/myevent.h"
#include <iostream>

MyEvent::MyEvent()
{
    _hasQuit = false;
    for (int i = 0; i < 322; i++) {
        _keys[i] = false;
    }
    
    _cameraRight = false;
    _cameraLeft = false;
    _cameraDown = false;
    _cameraUp = false;
}

MyEvent::~MyEvent()
{
    
}

void MyEvent::Update(unsigned int* deltaTime, Camera* pCamera)
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                _hasQuit = true;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym < 322 && event.key.keysym.sym > 0)
                    _keys[event.key.keysym.sym] = true;
                KeyDown(&event);
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym < 322 && event.key.keysym.sym > 0)
                    _keys[event.key.keysym.sym] = false;
                KeyUp(&event);
                break;
        }
    }
    
    float cameraSpeed = 2.5f * *deltaTime;
    if (_keys[SDLK_z]) 
        pCamera->Move(glm::vec3(0.0f, 0.0f, -0.05f));
    else if (_keys[SDLK_s])
        pCamera->Move(glm::vec3(0.0f, 0.0f, 0.05f));
    if (_keys[SDLK_d]) 
        pCamera->Move(glm::vec3(0.05f, 0.0f, 0.0f));
    else if (_keys[SDLK_q])
        pCamera->Move(glm::vec3(-0.05f, 0.0f, 0.0f));
    if (_cameraUp)
        pCamera->MoveTarget(glm::vec3(0.0f, 0.05f, 0.0f));
    else if (_cameraDown)
        pCamera->MoveTarget(glm::vec3(0.0f, -0.05f, 0.0f));
    if (_cameraRight)
        pCamera->MoveTarget(glm::vec3(0.05f, 0.0f, 0.0f));
    else if (_cameraLeft)
        pCamera->MoveTarget(glm::vec3(-0.05f, 0.0f, 0.0f));
}

void MyEvent::KeyDown(SDL_Event* myEvent)
{           
    switch (myEvent->key.keysym.sym) {
        case SDLK_ESCAPE:
            _hasQuit = true;
        case SDLK_p:
            _polygonMode = !_polygonMode;
            if (_polygonMode) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        case SDLK_UP:
            _cameraUp = true;
        case SDLK_DOWN:
            _cameraDown = true;
        case SDLK_RIGHT:
            _cameraRight = true;
        case SDLK_LEFT:
            _cameraLeft = true;
    }
}

void MyEvent::KeyUp(SDL_Event* myEvent)
{
    switch (myEvent->key.keysym.sym) {
        case SDLK_UP:
            _cameraUp = false;
        case SDLK_DOWN:
            _cameraDown = false;
        case SDLK_RIGHT:
            _cameraRight = false;
        case SDLK_LEFT:
            _cameraLeft = false;
    }
}

bool MyEvent::HasQuit()
{
    return _hasQuit;
}



