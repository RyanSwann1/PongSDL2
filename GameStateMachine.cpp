#include "GameStateMachine.h"


GameStateMachine::GameStateMachine()
{
}


GameStateMachine::~GameStateMachine()
{
}

void GameStateMachine::update()
{
	m_gameStates.back()->update();
}

void GameStateMachine::render()
{
	m_gameStates.back()->render();
}

void GameStateMachine::addState(GameState * state)
{
	m_gameStates.push_back(state); //Add new state to game states
	m_gameStates.back()->onEnter(); //Activate newly added state

}

void GameStateMachine::removeState(GameState* state)
{
	//If ther are existing game states
	if (!m_gameStates.empty())
	{
		//Remove state
		if (m_gameStates.back()->onExit())
		{
			//delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}

}

void GameStateMachine::changeState(GameState * state)
{
	//If there are already game states
	if (!m_gameStates.empty())
	{
		//If requested change of state is identical to current running state
		if (m_gameStates.back()->getStateID() == state->getStateID()) {
			return;
		}

		//Remove the current state
		if (m_gameStates.back()->onExit())
		{
			//delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}

	//Add our new state
	m_gameStates.push_back(state);
	//init state
	m_gameStates.back()->onEnter();
}