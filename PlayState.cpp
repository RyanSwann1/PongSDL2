#include "PlayState.h"
#include "Player.h"
#include "Opponent.h"
#include "Game.h"
#include <iostream>

const std::string PlayState::m_playStateID = "Play";

PlayState::PlayState()
{

}

PlayState::~PlayState()
{
}

void PlayState::update()
{
	//Update all game objects
	for(auto &gameObject : Game::instance()->getGameObjects())
	{ 
		gameObject->update();
	}
}

void PlayState::render()
{
	//Draw all game objects
	for (auto &gameObject : Game::instance()->getGameObjects())
	{
		gameObject->draw();
	}
}

bool PlayState::onEnter()
{
	Game::instance()->addGameObjects();
	std::cout << "Entering the play state.\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "Exiting the play state.\n";
	for (auto &gameObject : Game::instance()->getGameObjects())
	{
		delete gameObject;
	}
	Game::instance()->clearGameObjects();
	return true;
}
