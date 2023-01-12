#include "myMath.h"
#include "Level.h"




Vector2i Level::CreateMovementVector()               // I made this movement vectore So I can use it for movement of the player. It return the vector by calculating the key input.
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


// I made the add entity function. I use it to take the entity and store it in the list first and then in vector i store pointer to the entity in list

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


void Level::MovePlayer(Vector2i CreateMovementVector)     // This function I use to pass the movement generated and then i add it up to the current position of ship.
{
	Vector2i FuturePosition = all_entities[0]->Position + CreateMovementVector;
	
	if ((FuturePosition.x > 0) && (FuturePosition.x < 600 - 20) && (FuturePosition.y > 0) && (FuturePosition.y < 580 - 20))
	{
		all_entities[0]->Position = FuturePosition;
	}
	
}

// I made these spawn function. So I can give the different characterstics to every type and store it in vector. It also makes it easier to create entites only by calling functions

void Level::spawn_ship()
{
	Entity player;

	player.Position = { 400,400 };
	player.kind = EntityKind::SHIP;
	player.Radius = 20;
	player.dead = false;


	add_temp_entity(player);
}

void Level::spawn_laser()
{
	Entity laser;
	laser.Position = all_entities[0]->Position;
	laser.kind = EntityKind::LASER;
	laser.Radius = 10;
	laser.dead = false;
	laser.Direction = { 0,1 };

	add_temp_entity(laser);
}

void Level::spawn_rocks()
{
	Entity rocks;	

	rocks.Position.x = GetRandomValue(10, 590);
	rocks.Position.y = 0;
	rocks.kind = EntityKind::ROCKS;
	rocks.Radius = 12;
	rocks.dead = false;
	rocks.Direction = {static_cast<float>(GetRandomValue(-1,1)), 1 };
	add_temp_entity(rocks);
}

void Level::spawn_coins(Vector2i SpawnPos)
{
	Entity coin;

	for (int i = 0; i < 5; i++)
	{
		coin.Position.x = SpawnPos.x + GetRandomValue(20, 60);
		coin.Position.y = SpawnPos.y - GetRandomValue(20, 60);
		coin.Direction = { static_cast<float>(GetRandomValue(-1,1)),1 };
		coin.Radius = 5;

		coin.kind = EntityKind::COINS;
		coin.dead = false;
		add_temp_entity(coin);
	}
}

void Level::spawn_particles()
{
	Entity particles;

	particles.Position.x = GetRandomValue(-30, 560);
	particles.Position.y = 0;
	particles.kind = EntityKind::PARTICLES;
	particles.Radius = 2;
	particles.dead = false;
	particles.Direction = { static_cast<float>(GetRandomValue(-1,1)), 1 };
	add_temp_entity(particles);
}

// These two functions is the particles effect functions

void Level::spawn_smashed_particles(Vector2i SpawnPos)
{
	Entity smashed_particles;

	for (int i = 0; i < 7; i++)
	{
		smashed_particles.Position = { SpawnPos.x + GetRandomValue(-30,40), SpawnPos.y + GetRandomValue(0,40) };
		smashed_particles.kind = EntityKind::SMASHED_PARTICLES;
		smashed_particles.Radius = 4;
		smashed_particles.dead = false;
		smashed_particles.Direction = Math::random_direction();
		add_temp_entity(smashed_particles);
	}
}

void Level::PlayerInput()              // I made player input function So laser spawn here instead doing the logic in spawn functions.
{
	if (IsKeyPressed(KEY_Z))
	{
		PlaySoundMulti(ResourceManager::sound.LaserCharge);
	}
	if (IsKeyDown(KEY_Z))
	{
		laser_charge_timer++;
		if (laser_charge_timer == 60)
		{
			laser_charged = true;
			//StopSoundMulti();
		}

	}

	if (IsKeyReleased(KEY_Z) && laser_charged == true)
	{	
		PlaySoundMulti(ResourceManager::sound.LaserShoot);   // Sound on the spawn of the laser
		spawn_laser();
		laser_charged = false;
		laser_charge_timer = 0;
	}
}

void Level::Object_movement()       // I made this object movement function.So I can handle the movement of the all other entities except player on each updated frame.
{
	for (auto& e : all_entities)
	{
		switch (e->kind)
		{
		case(EntityKind::LASER):
		{
			e->Position.y -= static_cast<int>(e->Direction.y * TRAVEL_SPEED_LASER);

			if (e->Position.y <= 0)
			{
				e->dead = true;
			}

			break;
		}

		case(EntityKind::ROCKS):
		{
			e->Position.y += static_cast<int>(e->Direction.y * TRAVEL_SPEED_ROCKS);
			e->Position.x += static_cast<int>(e->Direction.x);

			if (e->Position.y >= 580 || e->Position.x <= 0 || e->Position.x >= 600)
			{
				e->dead = true;
			}

			break;
		}

		case(EntityKind::COINS):
		{
			e->Position.y += static_cast<int>(e->Direction.y * TRAVEL_SPEED_COIN);
			e->Position.x += e->Direction.x;

			if (e->Position.y == 580)
			{
				e->dead = true;
			}
			break;
		}

		case(EntityKind::PARTICLES):
		{
			e->Position.y += static_cast<int>(e->Direction.y * TRAVEL_SPEED_PARTICLE);

			e->Position.x += e->Direction.x;
			

			if (e->Position.y >= 580 || e->Position.x <= 0 || e->Position.x >= 600)
			{
				e->dead = true;
			}
			break;

		}

		case(EntityKind::SMASHED_PARTICLES):
		{
			e->Position.y += static_cast<int>(e->Direction.y * TRAVEL_SPEED_SMASHED_PARTICLES);

			e->Position.x += static_cast<int>(e->Direction.x * TRAVEL_SPEED_SMASHED_PARTICLES);

			if (e->Position.y >= 580 || e->Position.y <= 0 || e->Position.x <= 0 || e->Position.x >= 600)
			{
				e->dead = true;
			}
			break;
		}
		}
	}

}

void Level::ShipCollision()              // I made a one ship collisionbecause ship collides with multiple entities So I can handle all ship collision in this function
{
	for (auto* e : all_entities)
	{
		switch (e->kind)
		{
		case (EntityKind::SHIP):       // Ship and rock collision
			{

			for (Entity* e_rock : all_entities)
			{
				if (e_rock->kind == EntityKind::ROCKS)
				{
					// Bool function which checks for the collision and return true
					bool Collision = Math::Check_For_Collision(e_rock->Position, e->Position, e_rock->Radius, e->Radius);

					if (Collision)
					{
						PlaySoundMulti(ResourceManager::sound.LaserShoot);
						spawn_smashed_particles(e->Position);
						ShipCollided = true;
						e->dead = true;
					}
				}
			}
			}
			break;

		case (EntityKind::COINS):    // Ship and Coin collision
			{
			bool Collision = Math::Check_For_Collision(all_entities[0]->Position, e->Position, all_entities[0]->Radius, e->Radius);

				if (Collision)
				{
					PlaySoundMulti(ResourceManager::sound.CoinCollect);
					DrawText(TextFormat("+ %i", coin_value), e->Position.x + 20, e->Position.y - 20, 20, ORANGE);
					combo_timer_bool = true;
					score += coin_value;
					e->dead = true;
					if (combo_timer > 0)
					{
						coin_value += 10;
					}				
				}
			}
			break;
		}

	}
}

void Level::LaserRockCollision()             // This function i use totally for the laser and rock collision and I handle my spawn coin and my coin combo system here.
{
	if (combo_timer_bool)
	{
		combo_timer--;                 // I made this if statements outside the loop because i want it to run in everyframe but with condition.
	}

	if (combo_timer == 0)
	{
		coin_value = 50;
		combo_timer_bool = false;
		combo_timer = 60;
	}

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
						bool Collision = Math::Check_For_Collision(e_rock->Position, e->Position, e_rock->Radius, e->Radius);

						if (Collision)
						{
							PlaySoundMulti(ResourceManager::sound.RockBlast);
							spawn_coins(e_rock->Position);                     // spawn coins with the rock position
							spawn_smashed_particles(e_rock->Position);         // I spawn the coins and the particles here because i want them to spawn when the collision happens
							e_rock->dead = true;

						}
						
						
					}

					
				}

			}
			break;
		}		
	}
}

void Level::RefreshEntities()                 // Refresh entites i use this to remove the entities which got deleted but also move the added ones to the all_entities vector at the end of each frame So the vector doesn't go invalid 
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

void Level::ResetLevel()           // I use the reset level So I can reset all the entities and score to 0 before restarting game
{
	ShipCollided = false;
	EntitiesInList.clear();          // I clear my vector and list So when I restart I have totally empty new screen
	all_entities.clear();
	score = 0;

	spawn_ship();
}

void Level::update()              // In update I run all the functions which needed to update every frame of the game.
{
	//  This is the logic for spawning rock each frame.
	Rock_Spawn_index++;

	if (score >= 5000 && Rock_Spawn_index >= 10)
	{
		spawn_rocks();
	}
	else if (Rock_Spawn_index == 30)
	{
		spawn_rocks();
		
	}
	else if (score >= 3000 && Rock_Spawn_index >= 45)
	{
		spawn_rocks();
	}
	else if (Rock_Spawn_index > 60)
	{
		spawn_rocks();
		
		Rock_Spawn_index = 0;
	}

	PlayerInput();
	RefreshEntities();
	MovePlayer(CreateMovementVector());
	
	spawn_particles();
	Object_movement();
	ShipCollision();
	LaserRockCollision();

	

	
}

