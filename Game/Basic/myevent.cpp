#include "myevent.h"
#include <iostream>

MyEvent::MyEvent()
{
    m_hasQuit = false;
    for (int i = 0; i < 322; i++) {
        m_keys[i] = false;
    }
    
    m_lastMousePosX = 0;
    m_lastMousePosY = 0;
    m_mouseOffsetX = 0;
    m_mouseOffsetY = 0;
    m_leftClick = false;
    m_polygonMode = false;
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
                m_hasQuit = true;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym < 322 && event.key.keysym.sym > 0)
                    m_keys[event.key.keysym.sym] = true;
                KeyDown(&event);
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym < 322 && event.key.keysym.sym > 0)
                    m_keys[event.key.keysym.sym] = false;
                KeyUp(&event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                    m_leftClick = true;
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                    m_leftClick = false;
                break;
            case SDL_MOUSEWHEEL:
                if (event.button.button == SDL_BUTTON_LEFT)
                    m_leftClick = false;
                if (event.wheel.y > 0)
                    pCamera->Zoom(-0.5f);
                else if (event.wheel.y < 0)
                    pCamera->Zoom(0.5f);
                break;
        }
    }
    
    SDL_GetMouseState(&m_mousePosX, &m_mousePosY);
    //std::cout << m_mouseOffsetY << " ; " << m_mouseOffsetX << std::endl;
    
    if (m_leftClick) {
        m_mouseOffsetX = m_mousePosX - m_lastMousePosX;
        m_mouseOffsetY = m_mousePosY - m_lastMousePosY;
    
        //m_mouseOffsetY = 0;
        //m_mouseOffsetY = 270 - m_mousePosY;
    
        //m_mouseOffsetX = 0;
        //m_mouseOffsetX = 425 - m_mousePosX;
    }
    
    m_lastMousePosX = m_mousePosX;
    m_lastMousePosY = m_mousePosY;
    
    //std::cout << _leftClick << std::endl;
    
    if (m_leftClick) {
        if (abs(m_mouseOffsetY) < 300)
            pCamera->Rotate(0.0f, -m_mouseOffsetY / 20);
     
        if (abs(m_mouseOffsetX) < 300) 
            pCamera->Rotate(m_mouseOffsetX / 8, 0.0f);
    }

    
//     float cameraSpeed = 0.005f * *deltaTime;
//     if (_keys[SDLK_z]) 
//         pCamera->Move(cameraSpeed, false);
//     else if (_keys[SDLK_s])
//         pCamera->Move(-cameraSpeed, false);
//     if (_keys[SDLK_d]) 
//         pCamera->Move(cameraSpeed, true);
//     else if (_keys[SDLK_q])
//         pCamera->Move(-cameraSpeed, true);
    }

void MyEvent::KeyDown(SDL_Event* myEvent)
{           
    switch (myEvent->key.keysym.sym) {
        case SDLK_ESCAPE:
            m_hasQuit = true;
        case SDLK_p:
            m_polygonMode = !m_polygonMode;
            if (m_polygonMode) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

void MyEvent::KeyUp(SDL_Event* myEvent)
{
    switch (myEvent->key.keysym.sym) {
    }
}

bool MyEvent::HasQuit()
{
    return m_hasQuit;
}



