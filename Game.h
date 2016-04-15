#ifndef GAME_H
#define GAME_H


#include <SDL.h>
#include "GameStates.h"
#include "SDLGameObject.h"
#include <vector>

class MenuState;
class PlayState;
class GameStateMachine;
class Game
{
public:
	static Game* instance();

	bool init(const char* title, int sizeWidth, int sizeHeight);
	void update();
	void handleEvents();
	void render();
	void endGame() { m_running = false; }
	
	int getPlayingFieldHeight() const { return m_playingFieldHeight; }
	int getPlayingFieldWidth() const { return m_playingFieldWidth; }
	bool isRunning() const { return m_running; }
	void addGameObjects();
	void clearGameObjects();
	void resetGameObjects();

	std::vector<SDLGameObject*> getGameObjects() const{ return m_gameObjects; }
	SDL_Surface* getWindowSurface() const { return m_windowSurface; }
	SDL_Renderer* getRenderer() const { return m_renderer; }

private:

	static Game* m_instance;
	SDL_Window* m_window;
	SDL_Surface* m_windowSurface;
	SDL_Renderer* m_renderer;
	int m_playingFieldHeight = 500;
	int m_playingFieldWidth = 700;
	std::vector<SDLGameObject*> m_gameObjects;


	GameStateMachine* m_gameStateMachine;
	GameStates m_currentGameState;
	bool m_running;

	//Private so as not to be called from outside of the class
	Game();
	~Game();


};
#endif // !GAME_H

