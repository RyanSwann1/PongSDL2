#include "InputHandler.h"
#include "Game.h"

#include <iostream>

InputHandler * InputHandler::m_instance = nullptr;

InputHandler::InputHandler() : m_keyState(0)
{
	std::cout << "Inputhandler running.\n";
	
}

InputHandler::~InputHandler()
{
}


bool InputHandler::isKeyDown(SDL_Scancode key)
{
	//If key has been pressed
	if (m_keyState != 0)
	{
		//std::cout << "Key has been pressed.\n";
		//If specified key has been pressed
		if (m_keyState[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	//Key hasn't been pressed
	return false;
}

void InputHandler::update()
{
	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			Game::instance()->endGame(); 
			break;

		case SDL_KEYDOWN: 
			onKeyDown(); 
			break;

		case SDL_KEYUP: 
			onKeyUp(); 
			break;

		default: 
			break;
		}
	}
}

void InputHandler::onKeyDown()
{
	m_keyState = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
	m_keyState = SDL_GetKeyboardState(0);
}

InputHandler * InputHandler::instance()
{
	if (m_instance == nullptr) {
		m_instance = new InputHandler();
	}

	return m_instance;
}