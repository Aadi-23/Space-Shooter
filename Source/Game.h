#include <stack>
#include "Level.h"



enum class State              // This is menu struct i made to have different state which i can use for changing states
{
    MAIN_MENU,
	GAME,
	CONTROLS,
	MENUWHILEGAME,
	GAMESCREEN,
	ENDSCREEN,
	WINSCREEN
};

class Game
{
public:
	// This class which runs the actual game and i also handle the menu function here.
	bool Isrunning = true;

	State state;
	std::stack<State>states;

	int ShipIndex = 30;           // this index i made So i can delay the endscreen after dying

	Level level;

	void Do_mainmenu_frame();    // This function i use to layout the main menu
	void Menu_While_Game();      // This function i use to layout menu while game is running
};
