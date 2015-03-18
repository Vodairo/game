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
	ECHAP,
	SPACE,
	ENTER
};

class KeyboardHandler {
public:
	static KeyboardHandler* Instance();

	KeyboardStates PopKeyboardStack();
	void PushKeyboardStack(KeyboardStates state);


private:
	KeyboardHandler();
	~KeyboardHandler();

	static KeyboardHandler* FKeyboardHandler;

	std::list<KeyboardStates> FKeyboardStack;
};

}}

#endif