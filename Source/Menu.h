#include <stack>
#include<iostream>



enum class State
{
    MAIN_MENU,
	GAME,
	OPTIONS
};

class Game
{
public:

	bool Isrunning = true;
	State state;
	std::stack<State>states;

	void Do_mainmenu_frame();
};
