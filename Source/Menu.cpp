#include "Menu.h"
#include "myMath.h"
#include "raylib.h"


// This the gui label function i took from somewhere else which draws label for the menu

void gui_label(Rectangle rect, const char* label_text)
{
	Vector2i text_size = { MeasureText(label_text, 40), 40 };
	Vector2i text_top_left = (Vector2i{ static_cast<int>(rect.x),static_cast<int>(rect.y) } + (Vector2i{ static_cast<int>(rect.width),static_cast<int>(rect.height) } - text_size) / 2);

	DrawText(label_text, text_top_left.x,text_top_left.y,40,WHITE);
}

// This bool function i use which returns true if the mouse clicks on the menu labels

bool gui_button(Rectangle rect, const char* button_text)
{
	bool clicked = false;

	Color background_color = Color{ 64, 64, 64, 255 };

	if (CheckCollisionPointRec(GetMousePosition(), rect))
	{
		background_color = Color{ 96, 96, 96, 255 };

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			background_color = Color{ 32, 32, 32, 255 };
		}

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			clicked = true;
		}
	}

	DrawRectangle(rect.x, rect.y, rect.width,rect.height, background_color);
	gui_label(rect, button_text);

	return clicked;
}

// The do menu frame gets use to design the menu screen in the game and i handle states here.

void Game::Do_mainmenu_frame()
{
	const Vector2i button_size = Vector2i(300, 64);
	const int button_margin_y = 10;
	const int button_count = 3;

	Rectangle button_rect;
	button_rect.x = (GetRenderWidth() - button_size.x) / 2;
	button_rect.y = (GetRenderHeight() - (button_size.y * button_count) - (button_count - 1) * button_margin_y) / 2;
	button_rect.width = button_size.x;
	button_rect.height = button_size.y;

	if (gui_button(button_rect, "PLAY"))
	{                                                            // I push the state whenever the gui buttons get clicked 
		states.push(State::GAME);
	}
	button_rect.y += button_size.y + button_margin_y;

	if (gui_button(button_rect, "OPTIONS"))
	{
		states.push(State::OPTIONS);
	}
	button_rect.y += button_size.y + button_margin_y;

	if (gui_button(button_rect, "EXIT"))
	{
		Isrunning = false;
	}
}

void Game::Menu_While_Game()          // This function draws menu while game is in GAME state.
{
	const Vector2i button_size = Vector2i(300, 64);
	const int button_margin_y = 10;
	const int button_count = 3;

	Rectangle button_rect;
	button_rect.x = (GetRenderWidth() - button_size.x) / 2;
	button_rect.y = (GetRenderHeight() - (button_size.y * button_count) - (button_count - 1) * button_margin_y) / 2;
	button_rect.width = button_size.x;
	button_rect.height = button_size.y;

	if (gui_button(button_rect, "CONTINUE"))
	{                                                            // I push the state whenever the gui buttons get clicked 
		states.pop();
	}
	button_rect.y += button_size.y + button_margin_y;

	if (gui_button(button_rect, "RESTART"))
	{
		level.ResetLevel();
		states.pop();
	}
	button_rect.y += button_size.y + button_margin_y;

	if (gui_button(button_rect, "MAIN MENU"))
	{
		level.ResetLevel();
		states.pop();
		states.pop();
	}
}