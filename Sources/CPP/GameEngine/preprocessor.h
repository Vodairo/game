namespace Game {

// KEYBOARD

#define ADD_KEYSTATE(key, state) \
	case key: \
		KeyboardHandler::Instance()->PushKeyboardStack(state); \
		break;

// MAP

#define VECTOR3D(type) std::vector<std::vector<std::vector<##type##>>>

#define FOR2D(firstVar, secondVar, firstSize, secondSize) \
	for (int firstVar = 1; firstVar < firstSize; firstVar##++) \
		for (int secondVar = 0; secondVar < secondSize; secondVar##++)

}