#include <stdio.h>

#include "keyboardhandler.h"

namespace Game { namespace Keyboard {

KeyboardHandler* KeyboardHandler::Instance()
{
	if (FKeyboardHandler == nullptr)
		FKeyboardHandler = new KeyboardHandler();
	return FKeyboardHandler;
}

KeyboardStates KeyboardHandler::PopKeyboardStack()
{
	KeyboardStates state = KeyboardStates::VOID;

	state = FKeyboardStack.front();
	FKeyboardStack.pop_front();

	return state;
}

void KeyboardHandler::PushKeyboardStack(KeyboardStates state)
{
	FKeyboardStack.push_back(state);
}

}}