#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW\glfw3.h"

namespace Game {

class Window
{
public:
	static Window* Instance();
	~Window();

	bool IsOpen() const;

	GLFWwindow* GetWindow() const { return FWindow; };

private:
	Window();
	void Load();

	GLFWwindow* FWindow;
	bool FLoaded;
};

}

#endif