#include "myMath.h"
#include "Entity.h"




Vector2i Level::CreateMovementVector()
{
	int LRMV = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
	int UDMV = IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);

	return Vector2i(LRMV, UDMV);
}

void Level::MovePlayer(Vector2i CreateMovementVector)
{
	Vector2i FuturePosition = entities[0].Position + CreateMovementVector;


	entities[0].Position = FuturePosition;
}

void Level::spawn_fire()
{
	Entity laser;
	
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		laser.Position = entities[0].Position;
		laser.kind = EntityKind::LASER;

		entities.push_back(laser);
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
			e.Position.y -= static_cast<int>(TRAVEL_DIRECTION_Y * TRAVEL_SPEED_LASER);
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
	spawn_fire();
	spawn_rocks();
	Object_movement();
	
}

