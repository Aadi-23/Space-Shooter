#include "myMath.h"
#include "Entity.h"




Vector2i Level::CreateMovementVector()
{
	int LRMV = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
	int UDMV = IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);

	return Vector2i(LRMV,UDMV);
}

void Level::MovePlayer(Vector2i CreateMovementVector)
{
	Vector2i FuturePosition = entities[0].Position + CreateMovementVector;
	
	if ((FuturePosition.x > 0) && (FuturePosition.x < 80 - 4) && (FuturePosition.y > 0) && (FuturePosition.y < 65 - 4))
	{
		entities[0].Position = FuturePosition;
	}
	
}

void Level::spawn_laser()
{
	Entity laser;
	
	if (IsKeyDown(KEY_Z))
	{
		laser_charge_timer++;
		if (laser_charge_timer == 120)
		{
			laser.Position = entities[0].Position;
			laser.kind = EntityKind::LASER;

			entities.push_back(laser);

			laser_charge_timer = 0;
		}
	}
}

void Level::Object_movement()
{
	for (auto& e : entities)
	{
		switch (e.kind)
		{
		case(EntityKind::LASER):
		{

			if (IsKeyDown(KEY_Z))
			{
				e.Position = entities[0].Position;
			}
			if(IsKeyUp(KEY_Z))
			{
				e.Position.y -= static_cast<int>(TRAVEL_DIRECTION_Y * TRAVEL_SPEED_LASER);
			}

			if (e.Position != entities[0].Position)
			{
				e.Position.y -= static_cast<int>(TRAVEL_DIRECTION_Y * TRAVEL_SPEED_LASER);
			}
			


			break;
		}

		case(EntityKind::ROCKS):
		{
			e.Position.y += static_cast<int>(TRAVEL_DIRECTION_Y * TRAVEL_SPEED_ROCKS);
			break;
		}
		}
	}

}

void Level::spawn_rocks()
{
	Entity rocks;

	

	index++;

	if (index == 120)
	{
		rocks.Position.x = GetRandomValue(0, 80);

		rocks.Position.y = 0;
		rocks.kind = EntityKind::ROCKS;

		entities.push_back(rocks);

		index = 0;

		
	}
}

void Level::update()
{
	MovePlayer(CreateMovementVector());
	spawn_laser();
	Object_movement();
	spawn_rocks();
	
}

