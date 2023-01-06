#include "myMath.h"
#include "Entity.h"




Vector2i Level::CreateMovementVector()
{
	int LRMV = (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * TRAVEL_SPEED_SHIP;
	int UDMV = (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)) * TRAVEL_SPEED_SHIP;

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
	
	if ((FuturePosition.x > 0) && (FuturePosition.x < 800 - 20) && (FuturePosition.y > 0) && (FuturePosition.y < 450 - 20))
	{
		all_entities[0]->Position = FuturePosition;
	}
	
}

void Level::spawn_ship()
{
	Entity player;

	player.Position = { 400,400 };
	player.kind = EntityKind::SHIP;
	player.Raidus = 20;

	add_entity(player);
}

void Level::spawn_laser()
{
	Entity laser;
	
	
	if (IsKeyDown(KEY_Z))
	{
		laser_charge_timer++;

		if (laser_charge_timer == 60)
		{
			laser_charged = true;
		}
		
	}

	if(IsKeyReleased(KEY_Z) && laser_charged == true)
	{
		laser.Position = all_entities[0]->Position;
		laser.kind = EntityKind::LASER;
		laser.Raidus = 10;

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

			if (e->Position.y <= 0)
			{
				e->dead = true;
			}

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

	if (index == 30)
	{
		rocks.Position.x = GetRandomValue(0, 800);
		rocks.Position.y = 0;
		rocks.kind = EntityKind::ROCKS;
		rocks.Raidus = 12;

		add_entity(rocks);

		
	}
	if (index == 60)
	{
		rocks.Position.x = GetRandomValue(0, 800);
		rocks.Position.y = 0;
		rocks.kind = EntityKind::ROCKS;
		rocks.Raidus = 12;

		add_entity(rocks);
		index = 0;
	}
}

void Level::spawn_coins(Vector2i &SpawnPos)
{
	Entity coin;

	coin.Position = SpawnPos;
	coin.Position.y = 0;
	coin.Raidus = 5;

	coin.kind = EntityKind::COINS;

	add_entity(coin);

	
}

void Level::ShipCollision()
{
	for (auto* e : all_entities)
	{
		if (e->kind == EntityKind::ROCKS)
		{
			int a = static_cast<int>(e->Raidus + all_entities[0]->Raidus);
			int y = abs(e->Position.x - all_entities[0]->Position.x);
			int h = abs(e->Position.y - all_entities[0]->Position.y);

			if ((a ^ 2) >= (y ^ 2) + (h ^ 2))
			{
				ShipCollided = true;
				
			}
		}

	}
}

void Level::LaserRockCollision()
{
	for (Entity* e : all_entities)
	{
		if(e->kind == EntityKind::LASER)
		{
			for (Entity* rock : all_entities)
			{
				if (rock->kind == EntityKind::ROCKS)
				{
					int a = static_cast<int>(e->Raidus + rock->Raidus);
					int y = abs(e->Position.x - rock->Position.x);
					int h = abs(e->Position.y - rock->Position.y);

					if ((a ^ 2) >= (y ^ 2) + (h ^ 2))
					{
						score += 1;

						spawn_coins(e->Position);
					}
				}


			}

		}
				
		
		
	}
}

void Level::removeDeadEntities()
{
	auto last_entity = std::remove_if(all_entities.begin(), all_entities.end(), [](const Entity* e)->bool {return e->dead;});
	all_entities.erase(last_entity, all_entities.end());

	EntitiesInList.remove_if([](const Entity& e)-> bool { return e.dead; });
}

void Level::ResetLevel()
{
	ShipCollided = false;
	EntitiesInList.clear();
	all_entities.clear();
	score = 0;

	spawn_ship();
}

void Level::update()
{
	MovePlayer(CreateMovementVector());
	spawn_laser();
	Object_movement();
	spawn_rocks();
	ShipCollision();
	LaserRockCollision();

	removeDeadEntities();
	
}

