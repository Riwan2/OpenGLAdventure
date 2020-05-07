#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

struct DoubleInt {
    int X, Y;
    DoubleInt(const int& pX, const int& pY) : X(pX), Y(pY) {}
};

class Input
{
public:
    enum eAction {
        moveUp,
        moveRight,
        moveDown,
        moveLeft,
        jump,
        lineMode,
        quit,
    };
    
    static bool KeyDown(eAction action) { return keyDown[action]; }
    static bool KeyJustPressed(eAction action) { return (keyDown[action] && !lastKeyDown[action]); }
    
    enum eMouse {
        rightButton,
        leftButton,
        middleButton,
    };
    
    static bool& LeftClick(eMouse mouse) { return mouseDown[mouse]; }
    static DoubleInt& MousePosition() { return m_mousePosition; }
    static DoubleInt& MouseOffset() { return m_mouseOffset; }
    static DoubleInt& MouseWheel() { return m_mouseWheel; }
    static bool ScrollUp() { return m_mouseWheel.Y > 0; }
    static bool ScrollDown() { return m_mouseWheel.Y < 0; }
    static bool IsQuit;

    Input();
    ~Input();
    
    void Update();
private:
    void EventKeyDown(SDL_Event* myEvent);
    void EventKeyUp(SDL_Event* myEvent);

    static const int numAction = 7;
    static const int numMouse = 3;
    static bool keyDown[numAction];
    static bool lastKeyDown[numAction];
    static bool mouseDown[numMouse];
    static DoubleInt m_mousePosition, m_lastMousePosition, m_mouseOffset, m_mouseWheel;
};

#endif // INPUT_H
