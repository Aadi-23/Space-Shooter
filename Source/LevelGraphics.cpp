#include "Level.h"


void Level::render(Textures & texture)
{
	
	for (auto& e : all_entities)
	{
		DrawText(TextFormat("Score : %i", score), 300, 10, 25, WHITE);
		switch (e->kind)
		{
		case(EntityKind::SHIP):

			if (IsKeyDown(KEY_Z))
			{
				if (laser_charge_timer < 30)
				{
					DrawTexture(texture.ShipAnim1, e->Position.x - 25, e->Position.y - 50, WHITE);
			    }
			    if(laser_charge_timer >= 30)
				{
					DrawTexture(texture.ShipAnim2, e->Position.x - 25, e->Position.y - 50, WHITE);
				}
			}
			else
			{
				DrawTexture(texture.Ship, e->Position.x - 25, e->Position.y - 50, WHITE);
			}

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

		case(EntityKind::PARTICLES):
			DrawCircle(e->Position.x, e->Position.y, e->Radius, WHITE);

			break;

		case (EntityKind::SMASHED_PARTICLES):
			DrawCircle(e->Position.x, e->Position.y, e->Radius, RED);

			break;
		}
		

	}
	
}