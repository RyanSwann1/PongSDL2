#ifndef MENU_STATE_H
#define MENU_STATE_H


#include "GameState.h"
class MenuState :
	public GameState
{
public:
	MenuState();
	~MenuState();

	void update() override;
	void render() override;

	bool onEnter() override;
	bool onExit() override;

	std::string getStateID() const override { return m_menuID; }

private:
	static const std::string m_menuID;

};
#endif // !MENU_STATE_H
