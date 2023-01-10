#include "myMath.h"
#include <vector>
#include "Constants.h"
#include <list>
#include "ResourceManager.h"
#include "Entity.h"



class Level
{

	std::list<Entity> EntitiesInList;
	std::vector<Entity*>temp_entities;

	std::vector<Entity*> all_entities = {};

public:


	void render(Textures& texture);
	Vector2i CreateMovementVector();
	Vector2 random_direction();
	void MovePlayer(Vector2i CreateMovementVector);
	void add_temp_entity(const Entity& entities);
	void add_start_entity(const Entity & entities);
	int index = 0;
	int laser_charge_timer = 0;
	bool laser_charged = false;
	int score = 0;

	bool ShipCollided = false;

	void RefreshEntities();
	void spawn_ship();
	void spawn_laser();
	void spawn_rocks();
	void spawn_coins(Vector2i SpawnPos);
	void PlayerInput();
	void Object_movement();
	void ShipCollision();
	void LaserRockCollision();
	void ResetLevel();


	void spawn_particles();
	void spawn_smashed_particles(Vector2i SpawnPos);

	void update();


};