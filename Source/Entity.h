#include "myMath.h"
#include <vector>
#include "Constants.h"


enum class EntityKind
{
	NONE = 0,
	PLAYER,
	ROCKS,
	COINS,
};
;


class Entity
{
public:
	
	EntityKind kind;
	Vector2i Position;
};




class Level
{
public:
	void render();
	Vector2i CreateMovementVector();
	void MovePlayer(Vector2i CreateMovementVector);

	void spawn_fire();
	void fire_movement();

	void update();

	
	std::vector<Vector2i> Rocks;
	std::vector<Entity> entities{ Entity{EntityKind{EntityKind::PLAYER} , Vector2i{40,40} } };

};
