#include <GLFW\glfw3.h>

#include "GameEngine\window.h"

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

int main(int argc, char* argv[])
{
	FreeConsole();

	float ratio;
	int width, height;
	glfwGetFramebufferSize(Game::Window::Instance()->GetWindow(), &width, &height);
	ratio = width / (float) height;

	while (Game::Window::Instance()->IsOpen())
    {
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
		glfwSwapBuffers(Game::Window::Instance()->GetWindow());
        glfwPollEvents();
    }

    exit(EXIT_SUCCESS);
}