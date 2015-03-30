#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include "GLFW/glfw3.h"

#include <list>

namespace Game { namespace Keyboard {

enum KeyboardStates {
	VOID,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	JUMP,
	ESCAPE,
	ENTER
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

class KeyboardHandler {
public:
	static KeyboardHandler* Instance();
	~KeyboardHandler();

	KeyboardStates PopKeyboardStack();
	void PushKeyboardStack(KeyboardStates state);


private:
	KeyboardHandler();

	std::list<KeyboardStates>* FKeyboardStack;
};

}}

#endif