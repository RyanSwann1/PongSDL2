#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H

#include "GameState.h"
#include <vector>

class GameStateMachine
{
public:
	GameStateMachine();
	~GameStateMachine();


	void update();
	void render();
	void addState(GameState* state);
	void changeState(GameState* state);
	void removeState(GameState* state);

	
private:
	std::vector<GameState*> m_gameStates;
};
#endif // !GAME_STATE_MACHINE_H
