namespace Game {

#define ADD_KEYSTATE(key, state) \
	case key: \
		KeyboardHandler::Instance()->PushKeyboardStack(state); \
		break;

}