#include "MenuState.h"
#include <iostream>

const std::string MenuState::m_menuID = "MENU";

MenuState::MenuState()
{
	std::cout << "Hello World.";
}

MenuState::~MenuState()
{
}

void MenuState::update()
{
}

void MenuState::render()
{
}

bool MenuState::onEnter()
{
	std::cout << "Entering the menu state.\n";
	return true;
}

bool MenuState::onExit()
{
	std::cout << "Exiting the menu state.\n";
	return true;
}
