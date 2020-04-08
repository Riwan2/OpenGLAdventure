#ifndef MYEVENT_H
#define MYEVENT_H

#include <SDL2/SDL.h>
#include <GL/gl.h>

#include "camera.h"

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

    bool m_polygonMode;
    bool m_hasQuit;
    bool m_keys[322];
    bool m_leftClick;
    
    int m_mousePosX, m_mousePosY, m_lastMousePosX, m_lastMousePosY;
    float m_mouseOffsetX, m_mouseOffsetY;
};

#endif // MYEVENT_H
