#include <GLFW\glfw3.h>

#include "GameEngine\window.h"

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

int main(void)
{
	FreeConsole();

	Game::Window* game = new Game::Window();

	game->Load();

    while (game->IsOpen())
    {
        float ratio;
        int width, height;
		glfwGetFramebufferSize(game->GetWindow(), &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
		glfwSwapBuffers(game->GetWindow());
        glfwPollEvents();
    }
    exit(EXIT_SUCCESS);
}