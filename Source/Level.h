#include "myMath.h"
#include <vector>
#include "Constants.h"
#include <list>
#include "ResourceManager.h"
#include "Entity.h"



class Level
{

	std::list<Entity> EntitiesInList;

	std::vector<Entity*> all_entities = {};

public:

	ResourceManager resources;

	void render(Textures& texture);
	Vector2i CreateMovementVector();
	void MovePlayer(Vector2i CreateMovementVector);
	void add_entity(const Entity& entities);
	int index = 0;
	int laser_charge_timer = 0;
	bool laser_charged = false;
	int score = 0;

	bool ShipCollided = false;

	void removeDeadEntities();
	void spawn_ship();
	void spawn_laser();
	void spawn_rocks();
	void spawn_coins(Vector2i SpawnPos);
	void Object_movement();
	void ShipCollision();
	void LaserRockCollision();
	void ResetLevel();


	void update();


};