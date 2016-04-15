#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	
	static InputHandler *instance();

	bool isKeyDown(SDL_Scancode key);

	void update();
	void onKeyDown();
	void onKeyUp();
private:

	static InputHandler *m_instance;
	const Uint8 *m_keyState;
	
};
#endif // !INPUT_HANDLER_H
