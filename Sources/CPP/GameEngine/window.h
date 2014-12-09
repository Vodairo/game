#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW\glfw3.h"

namespace Game
{
    class Window
    {
    public:
        void Load();
        bool IsLoaded() const;

    private:
        GLFWwindow* FWindow;
    }
}

#endif