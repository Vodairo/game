
#include <stdlib.h>
#include <stdio.h>

#include "window.h"

namespace Game {

Window* Window::Instance()
{
	static Window* FWindowInstance = nullptr;

	if (FWindowInstance == nullptr)
	{
		FWindowInstance = new Window();
		FWindowInstance->Load();
	}

	return FWindowInstance;
}

Window::Window()
	: FLoaded(false)
{
}

Window::~Window()
{
	glfwDestroyWindow(FWindow);
    glfwTerminate();
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void Window::Load()
{
	if (!glfwInit())
		exit(EXIT_FAILURE);
	FWindow = glfwCreateWindow(640, 480, "Game", NULL, NULL);
	
	if (!FWindow)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(FWindow);
	glfwSetKeyCallback(FWindow, key_callback);

	FLoaded = true;
}

bool Window::IsOpen() const
{
	if (FLoaded)
		if (!glfwWindowShouldClose(FWindow))
			return true;

	return false;
}

}