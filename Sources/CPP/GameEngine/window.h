#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW\glfw3.h"

namespace Game {

class Window
{
public:
	Window();
	~Window();

    void Load();
    bool IsOpen() const;

	GLFWwindow* GetWindow() const { return FWindow; };

private:
    GLFWwindow* FWindow;
	bool FLoaded;
};

}

#endif