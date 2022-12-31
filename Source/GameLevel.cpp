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
	Entity rock;
	
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		rock.Position = entities[0].Position;
		rock.kind = EntityKind::ROCKS;

		entities.push_back(rock);
	}
}

void Level::fire_movement()
{
	for (auto& e : entities)
	{
		switch(e.kind)
		{
		case(EntityKind::ROCKS):
			{
			e.Position.y -= (int)TRAVEL_DIRECTION * TRAVEL_SPEED;
			}
		}
	}
}

void Level::update()
{
	MovePlayer(CreateMovementVector());
	spawn_fire();
	fire_movement();
	
}