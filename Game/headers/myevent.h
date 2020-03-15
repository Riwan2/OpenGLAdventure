#ifndef MYEVENT_H
#define MYEVENT_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "../headers/camera.h"

class MyEvent
{
public:
    MyEvent();
    ~MyEvent();
    
    void Update(unsigned int* deltaTime, Camera* pCamera);
    bool HasQuit();

private:
    void KeyDown(SDL_Event* myEvent);
    void KeyUp(SDL_Event* myEvent);

    bool _polygonMode;
    bool _hasQuit;
    bool _keys[322];
    bool _cameraUp;
    bool _cameraDown;
    bool _cameraRight;
    bool _cameraLeft;
};

#endif // MYEVENT_H
