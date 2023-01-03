#include "Entity.h"

void Level::render()
{
	
	for (auto& e : all_entities)
	{
		DrawText(TextFormat("Score : %i", score), 350, 10, 25, WHITE);
		switch (e->kind)
		{
		case(EntityKind::SHIP):
			DrawRectangle(e->Position.x * 10, e->Position.y * 10, 40, 40, RED);

			break;

		case(EntityKind::LASER):

			DrawRectangle(e->Position.x * 10 + 10, e->Position.y * 10, 20, 20, ORANGE);
			break;

		case(EntityKind::ROCKS):

			DrawRectangle(e->Position.x * 10, e->Position.y * 10, 40, 40, GRAY);
			break;
		}
		

	}
	
}