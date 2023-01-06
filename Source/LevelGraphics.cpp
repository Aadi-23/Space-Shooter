#include "Entity.h"


void Level::render(Textures & texture)
{
	
	for (auto& e : all_entities)
	{
		DrawText(TextFormat("Score : %i", score), 350, 10, 25, WHITE);
		switch (e->kind)
		{
		case(EntityKind::SHIP):
			DrawCircle(e->Position.x , e->Position.y , e->Raidus,WHITE);
			DrawTexture(texture.Ship, e->Position.x - 20,e->Position.y - 20, WHITE);

			break;

		case(EntityKind::LASER):

			DrawCircle(e->Position.x +10, e->Position.y, e->Raidus, ORANGE);
			break;

		case(EntityKind::ROCKS):

			DrawCircle(e->Position.x , e->Position.y, e->Raidus, GRAY);
			break;
		case(EntityKind::COINS):

			DrawCircle(e->Position.x, e->Position.y, e->Raidus, YELLOW);
			break;
		}
		

	}
	
}