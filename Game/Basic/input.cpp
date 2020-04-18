#include "input.h"
#include <iostream>

bool Input::keyDown[] = {0};
bool Input::lastKeyDown[] = {0};
bool Input::mouseDown[] = {0};
DoubleInt Input::m_mousePosition = DoubleInt(0, 0);
DoubleInt Input::m_lastMousePosition = DoubleInt(0, 0);
DoubleInt Input::m_mouseOffset = DoubleInt(0, 0);
DoubleInt Input::m_mouseWheel = DoubleInt(0, 0);

Input::Input()
{    
}

Input::~Input()
{
    
}

void Input::Update()
{
    SDL_Event event;
    m_mouseWheel.X = 0;
    m_mouseWheel.Y = 0;
    
    for (int i = 0; i < numAction; i++) {
        lastKeyDown[i] = keyDown[i];
    }
    
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN:
                EventKeyDown(&event);
                break;
            case SDL_KEYUP:
                EventKeyUp(&event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                    mouseDown[Input::eMouse::leftButton] = true;
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                    mouseDown[Input::eMouse::leftButton] = false;
                break;
            case SDL_MOUSEWHEEL:
                m_mouseWheel.X = event.wheel.x;
                m_mouseWheel.Y = event.wheel.y;
        }
    }
    
    SDL_GetMouseState(&m_mousePosition.X, &m_mousePosition.Y);
    m_mouseOffset.X = m_mousePosition.X - m_lastMousePosition.X;
    m_mouseOffset.Y = m_mousePosition.Y - m_lastMousePosition.Y;
    m_lastMousePosition = m_mousePosition;
}

void Input::EventKeyDown(SDL_Event* myEvent)
{           
    switch (myEvent->key.keysym.sym) {
        case SDLK_ESCAPE:
            keyDown[Input::eAction::quit] = true;
            break;
        case SDLK_p:
            keyDown[Input::eAction::lineMode] = true;
            break;
        case SDLK_z:
            keyDown[Input::eAction::moveUp] = true;
            break;
        case SDLK_d:
            keyDown[Input::eAction::moveRight] = true;
            break;
        case SDLK_s:
            keyDown[Input::eAction::moveDown] = true;
            break;
        case SDLK_q:
            keyDown[Input::eAction::moveLeft] = true;
            break;
    }
}

void Input::EventKeyUp(SDL_Event* myEvent)
{
    switch (myEvent->key.keysym.sym) {
        case SDLK_ESCAPE:
            keyDown[Input::eAction::quit] = false;
            break;
        case SDLK_p:
            keyDown[Input::eAction::lineMode] = false;
            break;
        case SDLK_z:
            keyDown[Input::eAction::moveUp] = false;
            break;
        case SDLK_d:
            keyDown[Input::eAction::moveRight] = false;
            break;
        case SDLK_s:
            keyDown[Input::eAction::moveDown] = false;
            break;
        case SDLK_q:
            keyDown[Input::eAction::moveLeft] = false;
            break;
    }
}
