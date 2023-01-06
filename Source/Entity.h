#include "myMath.h"
#include <vector>
#include "Constants.h"
#include <list>
#include "ResourceManager.h"

enum class EntityKind
{
	NONE = 0,
	SHIP,
	LASER,
	ROCKS,
	COINS,
};
;


class Entity
{
public:
	
	EntityKind kind = {};
	Vector2i Position = { 0,0 };

	float Raidus = 0;

	bool dead = false;
};




class Level
{
	std::list<Entity> EntitiesInList;
	
	std::vector<Entity*> all_entities = {};
	

public:
	
	void render(Textures &texture);
	Vector2i CreateMovementVector();
	void MovePlayer(Vector2i CreateMovementVector);
	void add_entity(const Entity & entities);
	int index = 0;
	int laser_charge_timer = 0;
	bool laser_charged = false;
	int score = 0;

	bool ShipCollided = false;

	void removeDeadEntities();
	void spawn_ship();
	void spawn_laser();
	void spawn_coins(Vector2i& SpawnPos);
	void spawn_rocks();
	void Object_movement();
	void ShipCollision();
	void LaserRockCollision();
	void ResetLevel();


	void update();


};
