#ifndef MYEVENT_H
#define MYEVENT_H

#include <SDL2/SDL.h>
#include <GL/gl.h>

class MyEvent
{
public:
    MyEvent();
    ~MyEvent();
    
    void Update();
    bool HasQuit();

private:
    void KeyDown(SDL_Event* myEvent);

    bool _polygonMode;
    bool _hasQuit;
};

#endif // MYEVENT_H
