#include "myMath.h"
#include <vector>
#include "Constants.h"
#include <list>
#include "ResourceManager.h"
#include "Entity.h"
#include "raymath.h"
#include "raylib.h"


class Level
{

	std::list<Entity> EntitiesInList;        // I made the list of entity where i store all the entities. I used list instead vector because of resizing issue of vector.
	std::vector<Entity*>temp_entities;       // I made this temp vector So I can store the entites getting added during runtime and it add those entities at end of each update
	std::vector<Entity*> all_entities = {};  // This vector I use to store all the pointer to the entity in the EntityInList

public:
	// I declared all the variables because they need to run on each update and i use them at different places in my code.

	int Rock_Spawn_index = 0;
	int laser_charge_timer = 0;
	bool laser_charged = false;
	int score = 0;
	int combo_timer = 60;
	bool combo_timer_bool = false;
	int coin_value = 50;
	bool ShipCollided = false;

	int combonumtimer = 10;
	bool combonumbool = false;

	// These i made So I can control the duration ofd screen shake
	int screenshaketimer = 20;
	bool screen_shake_bool = false;

	//Camera for screen shake
	Camera2D screen_shake_camera = {0};
	
	
	// I made all the functions here which happens in game because they run when the level starts which is game screen.

	void render(Textures& texture);
	Vector2i CreateMovementVector();
	
	void MovePlayer(Vector2i CreateMovementVector);
	void add_temp_entity(const Entity& entities);
	void add_start_entity(const Entity & entities);


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