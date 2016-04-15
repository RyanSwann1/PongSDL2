#include "Game.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Opponent.h"
#include "Ball.h"

#include <assert.h>
#include <iostream>

Game* Game::m_instance = nullptr;

Game::Game()
{

	std::cout << "Game Running.";
}

Game::~Game()
{

}

Game * Game::instance()
{
	if (m_instance == nullptr) {
		m_instance = new Game();
	}

	return m_instance;
}

bool Game::init(const char* title, int sizeWidth, int sizeHeight)
{
	//Initialize SDL Video
	SDL_INIT_VIDEO;
	//Initialize SDL Window
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sizeWidth, sizeHeight, SDL_WINDOW_SHOWN);
	assert(m_window != nullptr);

	//Create window surface
	m_windowSurface = SDL_GetWindowSurface(m_window);
	assert(m_windowSurface != nullptr);

	//Initialize Renderer 
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	assert(m_renderer != nullptr);

	//Set current state to the menu state
	m_currentGameState = GameStates::MENU; 
	std::cout << "Before INIT State.\n";
	//Initialize the menu state
	m_gameStateMachine = new GameStateMachine();
	m_gameStateMachine->changeState(new MenuState());
	std::cout << "After INIT State.\n";

	//Load all game textures
	TextureManager::instance()->load("Player", "Paddle.BMP");
	TextureManager::instance()->load("Ball", "Ball.BMP");
	TextureManager::instance()->load("Opponent", "Paddle.BMP");


	//Initiazzation has been successful
	m_running = true;
	return true;
	
}

void Game::handleEvents()
{
	InputHandler::instance()->update();

	if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		m_gameStateMachine->changeState(new PlayState());
	}

	else if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		m_gameStateMachine->changeState(new MenuState());
	}
}

void Game::update()
{
	m_gameStateMachine->update();
}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	//m_gameStateMachine
	

	//Render Under Game State
	m_gameStateMachine->render();
	
	//Apply all rendering
	SDL_RenderPresent(m_renderer);
}

void Game::addGameObjects()
{
	m_gameObjects.push_back(new Player());
	m_gameObjects.push_back(new Opponent());
	m_gameObjects.push_back(new Ball());
}

void Game::clearGameObjects()
{
	m_gameObjects.clear();
}

void Game::resetGameObjects()
{
	for (auto &gameObject : m_gameObjects)
	{
		gameObject->reset();
	}
}
