#include "Menu.h"
#include "myMath.h"
#include "raylib.h"


void GameMenu::Do_main_frame()
{
	const Vector2i button_size = Vector2i(300, 64);
	const int button_margin_y = 10;
	const int button_count = 3;

	/*Rectangle2i button_rect;
	button_rect.min = (get_window_size() - button_size * Vector2i(1, button_count) - Vector2i(0, button_count - 1) * button_margin_y) / 2;
	button_rect.size = button_size;

	if (gui_button(button_rect, "PLAY"))
	{
		states.push(State::GAME);
	}
	button_rect.min.y += button_size.y + button_margin_y;

	if (gui_button(button_rect, "OPTIONS"))
	{
		states.push(State::OPTIONS);
	}
	button_rect.min.y += button_size.y + button_margin_y;

	if (gui_button(button_rect, "EXIT"))
	{
		close_window();
	}*/
}