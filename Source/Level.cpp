#include "myMath.h"
#include "Level.h"




Vector2i Level::CreateMovementVector()
{
	if (IsKeyDown(KEY_Z))
	{
		int LRMV = (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * TRAVEL_SPEED_SHIP_CHARGING;
		int UDMV = (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)) * TRAVEL_SPEED_SHIP_CHARGING;
		return Vector2i(LRMV, UDMV);
	}
	else
	{
		int LRMV = (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * TRAVEL_SPEED_SHIP;
		int UDMV = (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)) * TRAVEL_SPEED_SHIP;
		return Vector2i(LRMV, UDMV);
	}

	
}

void Level::add_temp_entity(const Entity &entities)
{
	EntitiesInList.push_back(entities);
	temp_entities.push_back(&EntitiesInList.back());
}

void Level::add_start_entity(const Entity& entities)
{
	EntitiesInList.push_back(entities);
	all_entities.push_back(&EntitiesInList.back());

}


void Level::MovePlayer(Vector2i CreateMovementVector)
{
	Vector2i FuturePosition = all_entities[0]->Position + CreateMovementVector;
	
	if ((FuturePosition.x > 0) && (FuturePosition.x < 600 - 20) && (FuturePosition.y > 0) && (FuturePosition.y < 580 - 20))
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
	player.dead = false;


	add_temp_entity(player);
}

void Level::spawn_laser()
{
	Entity laser;
	laser.Position = all_entities[0]->Position;
	laser.kind = EntityKind::LASER;
	laser.Raidus = 10;
	laser.dead = false;

	add_temp_entity(laser);
}

void Level::spawn_rocks()
{
	Entity rocks;	

	rocks.Position.x = GetRandomValue(10, 590);
	rocks.Position.y = 0;
	rocks.kind = EntityKind::ROCKS;
	rocks.Raidus = 12;
	rocks.dead = false;
	add_temp_entity(rocks);
}

void Level::PlayerInput()
{
	if (IsKeyDown(KEY_Z))
	{
		laser_charge_timer++;

		if (laser_charge_timer == 60)
		{
			laser_charged = true;
		}

	}

	if (IsKeyReleased(KEY_Z) && laser_charged == true)
	{	
		spawn_laser();
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

			if (e->Position.y == 580)
			{
				e->dead = true;
			}

			break;
		}

		case(EntityKind::COINS):
		{
			e->Position.y += static_cast<int>(TRAVEL_DIRECTION_Y * TRAVEL_SPEED_COIN);

			if (e->Position.y == 580)
			{
				e->dead = true;
			}
			break;
		}

		case(EntityKind::PARTICLES):
		{
			e->Position.y += static_cast<int>(TRAVEL_DIRECTION_Y * TRAVEL_SPEED_PARTICLE);

			e->Position.x += 1;

			if (e->Position.y == 580)
			{
				e->dead = true;
			}
		}
		}
	}

}


void Level::spawn_coins(Vector2i SpawnPos)
{
	Entity coin;

	
	

	for(int i = 0; i<5; i++)
	{
		coin.Position.x = SpawnPos.x + GetRandomValue(0, 60);
		coin.Position.y = SpawnPos.y - GetRandomValue(0, 60);

		coin.Raidus = 5;

		coin.kind = EntityKind::COINS;
		coin.dead = false;
		add_temp_entity(coin);
	}
	

	
}

void Level::ShipCollision()
{
	for (auto* e : all_entities)
	{
		switch (e->kind)
		{
		case (EntityKind::ROCKS):
			{
				int a = static_cast<int>(e->Raidus + all_entities[0]->Raidus);
				int y = abs(e->Position.x - all_entities[0]->Position.x);
				int h = abs(e->Position.y - all_entities[0]->Position.y);

				if ((a ^ 2) >= (y ^ 2) + (h ^ 2))
				{
					ShipCollided = true;

				}
			}
			break;

		case (EntityKind::COINS):
			{
				int a = static_cast<int>(e->Raidus + all_entities[0]->Raidus);
				int y = abs(e->Position.x - all_entities[0]->Position.x);
				int h = abs(e->Position.y - all_entities[0]->Position.y);

				if ((a ^ 2) >= (y ^ 2) + (h ^ 2))
				{
					score += 1;
					e->dead = true;
				}
			}
			break;
		}

	}
}

void Level::LaserRockCollision()
{
	for (Entity* e : all_entities)
	{
		switch (e->kind)
		{
		case(EntityKind::LASER):
			{
				for (Entity* e_rock : all_entities)
				{
					if (e_rock->kind == EntityKind::ROCKS)
					{
						int a = static_cast<int>(e->Raidus + e_rock->Raidus);
						int y = abs(e->Position.x - e_rock->Position.x);
						int h = abs(e->Position.y - e_rock->Position.y);

						if ((a ^ 2) >= (y ^ 2) + (h ^ 2))
						{
							PlaySoundMulti(ResourceManager::sound.RockBlast);
							spawn_coins(e_rock->Position);
							e_rock->dead = true;

						}
						
						
					}

					
				}

			}
			break;

			
		
		}
		
		
	}
}

void Level::RefreshEntities()
{
	auto last_entity = std::remove_if(all_entities.begin(), all_entities.end(), [](const Entity* e)->bool {return e->dead;});
	all_entities.erase(last_entity, all_entities.end());

	EntitiesInList.remove_if([](const Entity& e)-> bool { return e.dead; });

	while (temp_entities.size() != 0)
	{
		all_entities.push_back(temp_entities.back());
		temp_entities.pop_back();
	}

}

void Level::ResetLevel()
{
	ShipCollided = false;
	EntitiesInList.clear();
	all_entities.clear();
	score = 0;

	spawn_ship();
}

void Level::spawn_particles()
{
	Entity particles;

	particles.Position.x = GetRandomValue(10, 590);
	particles.Position.y = 0;
	particles.kind = EntityKind::PARTICLES;
	particles.Raidus = 2;
	particles.dead = false;
	add_temp_entity(particles);
	
}

void Level::update()
{
	index++;

	if (index == 30)
	{
		spawn_rocks();
		
	}
	else if (index > 60)
	{
		spawn_rocks();
		
		index = 0;
	}

	PlayerInput();
	RefreshEntities();
	MovePlayer(CreateMovementVector());
	
	spawn_particles();
	Object_movement();
	ShipCollision();
	LaserRockCollision();

	

	
}

