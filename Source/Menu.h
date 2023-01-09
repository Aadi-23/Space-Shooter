#include <stack>



enum class State
{
    MAIN_MENU,
	GAME,
	OPTIONS
};

class GameMenu
{
public:
	std::stack<State>states;

	void Do_main_frame();
};
