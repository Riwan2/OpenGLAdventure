#include "../headers/myevent.h"

MyEvent::MyEvent()
{
    _hasQuit = false;
}

MyEvent::~MyEvent()
{
    
}

void MyEvent::Update()
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event)) {
        switch(event.type) {  
            case SDL_QUIT:
                _hasQuit = true;
            case SDL_KEYDOWN:
                KeyDown(&event);
        }
    }
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
    }
}


bool MyEvent::HasQuit()
{
    return _hasQuit;
}



