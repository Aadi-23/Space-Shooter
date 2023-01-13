#include "Level.h"


void Level::render(Textures & texture)
{
	BeginMode2D(screen_shake_camera);
	for (Entity* e : all_entities)
	{
		
		DrawText(TextFormat("Score : %i", score), 300, 10, 25, WHITE);
		switch (e->kind)
		{
		case(EntityKind::SHIP):
		{
			// This is lerp code i made to move object towards the ship without doing animations. LaserL stands for left laser and LaserR for right laser.
			Vector2 laserR_spawn_pos = {(e->Position.x + 30),(e->Position.y - 60) };                              
			Vector2 laserL_spawn_pos = {(e->Position.x - 30),(e->Position.y - 60) };

			// Lerp code for each axis
			laserR_spawn_pos.x = Lerp(laserR_spawn_pos.x, e->Position.x, laser_charge_timer / 60.f);
			laserR_spawn_pos.y = Lerp(laserR_spawn_pos.y, e->Position.y, laser_charge_timer / 60.f);
			laserL_spawn_pos.x = Lerp(laserL_spawn_pos.x, e->Position.x, laser_charge_timer / 60.f);
			laserL_spawn_pos.y = Lerp(laserL_spawn_pos.y, e->Position.y, laser_charge_timer / 60.f);

			

			if (laser_charge_timer > 30 && laser_charge_timer <= 45)
			{
				DrawTexture(texture.ShipAnim1, e->Position.x - 25, e->Position.y - 50, WHITE);
			}
			else if ( laser_charge_timer != 0 && laser_charge_timer > 45)
			{
				DrawTexture(texture.ShipAnim2, e->Position.x - 25, e->Position.y - 50, WHITE);
			}
			else
			{
				DrawTexture(texture.Ship, e->Position.x - 25, e->Position.y - 50, WHITE);
			}

			if (laser_charge_timer != 0 && laser_charge_timer < 30)
			{
				DrawTexture(texture.LaserAnim0, laserR_spawn_pos.x - 15, laserR_spawn_pos.y - 15, WHITE);
				DrawTexture(texture.LaserAnim0, laserL_spawn_pos.x - 15, laserL_spawn_pos.y - 15, WHITE);
			}
		    break;
		}

		case(EntityKind::LASER):

			DrawTexture(texture.Laser, e->Position.x - 14, e->Position.y - 14, WHITE);
			break;

		case(EntityKind::ROCKS):

			DrawTexture(texture.Rocks, e->Position.x - 15, e->Position.y - 15, WHITE);
			break;

		case(EntityKind::COINS):

			DrawTexture(texture.Coins, e->Position.x - 5, e->Position.y - 10, WHITE);
			break;

		case(EntityKind::PARTICLES):
			DrawCircle(e->Position.x, e->Position.y, e->Radius, WHITE);

			break;

		case (EntityKind::SMASHED_PARTICLES):
			DrawTexture(texture.SmashedParticles, e->Position.x, e->Position.y, WHITE);
			break;
		}

	}
	
	EndMode2D();
}
