#ifndef __MENU_STATE__
#define __MENU_STATE__

#include "GameState.h"
#include "GameObject.h"
#include "Game.h"
#include <vector>

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const {return s_menuID; }

private:
	// call back functions for menu items
	static void s_menuToPlay();
	static void s_exitFromMenu();
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;

};

#endif