#include <stdio.h>

#include "keyboardhandler.h"

#include "preprocessor.h"

namespace Game { namespace Keyboard {

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (action)
	{
	case GLFW_PRESS:
		switch (key)
		{
		ADD_KEYSTATE(GLFW_KEY_Z, UP);
		ADD_KEYSTATE(GLFW_KEY_S, DOWN);
		ADD_KEYSTATE(GLFW_KEY_Q, LEFT);
		ADD_KEYSTATE(GLFW_KEY_D, RIGHT);
		ADD_KEYSTATE(GLFW_KEY_SPACE, JUMP);
		ADD_KEYSTATE(GLFW_KEY_ESCAPE, ESCAPE);
		default:
			break;
		}
		break;
	default:
		break;
	}
}

KeyboardHandler* KeyboardHandler::Instance()
{
	if (FKeyboardHandlerInstance == nullptr)
		FKeyboardHandlerInstance = new KeyboardHandler();
	return FKeyboardHandlerInstance;
}

KeyboardHandler::KeyboardHandler()
{
	FKeyboardStack = new std::list<KeyboardStates>();
}

KeyboardHandler::~KeyboardHandler()
{
	delete FKeyboardStack;
}


KeyboardStates KeyboardHandler::PopKeyboardStack()
{
	KeyboardStates state = KeyboardStates::VOID;

	if (FKeyboardStack->size() > 0)
	{
		state = FKeyboardStack->front();
		FKeyboardStack->pop_front();
	}

	return state;
}

void KeyboardHandler::PushKeyboardStack(KeyboardStates state)
{
	FKeyboardStack->push_back(state);
}

}}