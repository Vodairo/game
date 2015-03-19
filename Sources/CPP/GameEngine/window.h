#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW\glfw3.h"

namespace Game {

class Window
{
public:
	static Window* Instance();

	bool IsOpen() const;

	GLFWwindow* GetWindow() const { return FWindow; };

private:
	Window();
	~Window();

	void Load();

	static Window* FWindowInstance;

	GLFWwindow* FWindow;
	bool FLoaded;
};

}

#endif