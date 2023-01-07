#include "Level.h"


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

			DrawTexture(texture.Laser, e->Position.x - 14, e->Position.y - 14, WHITE);
			break;

		case(EntityKind::ROCKS):

			DrawTexture(texture.Rocks, e->Position.x - 15 , e->Position.y - 15, WHITE);
			break;

		case(EntityKind::COINS):

			DrawTexture(texture.Coins, e->Position.x - 5, e->Position.y - 10, WHITE);
			break;
		}
		

	}
	
}