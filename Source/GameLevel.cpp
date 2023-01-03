#include "myMath.h"
#include "Entity.h"




Vector2i Level::CreateMovementVector()
{
	int LRMV = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
	int UDMV = IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);

	return Vector2i(LRMV,UDMV);
}

void Level::add_entity(const Entity &entities)
{
	EntitiesInList.push_back(entities);
	all_entities.push_back(&EntitiesInList.back());
}

void Level::MovePlayer(Vector2i CreateMovementVector)
{
	Vector2i FuturePosition = all_entities[0]->Position + CreateMovementVector;
	
	if ((FuturePosition.x > 0) && (FuturePosition.x < 80 - 4) && (FuturePosition.y > 0) && (FuturePosition.y < 65 - 4))
	{
		all_entities[0]->Position = FuturePosition;
	}
	
}

void Level::spawn_ship()
{
	Entity player;

	player.Position = { 40,40 };
	player.kind = EntityKind::PLAYER;

	add_entity(player);
}

void Level::spawn_laser()
{
	Entity laser;
	
	
	if (IsKeyDown(KEY_Z))
	{
		laser_charge_timer++;

		if (laser_charge_timer == 120)
		{
			laser_charged = true;
		}
		
	}

	if(IsKeyReleased(KEY_Z) && laser_charged == true)
	{
		laser.Position = all_entities[0]->Position;
		laser.kind = EntityKind::LASER;

		add_entity(laser);
		laser_charged = false;
		laser_charge_timer = 0;
	}
}

void Level::Object_movement()
{
	for (auto& e : all_entities)
	{
		switch (e->kind)
		{
		case(EntityKind::LASER):
		{
			e->Position.y -= static_cast<int>(TRAVEL_DIRECTION_Y * TRAVEL_SPEED_LASER);

			break;
		}

		case(EntityKind::ROCKS):
		{
			e->Position.y += static_cast<int>(TRAVEL_DIRECTION_Y * TRAVEL_SPEED_ROCKS);
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

		add_entity(rocks);

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

