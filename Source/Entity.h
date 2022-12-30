#include "myMath.h"
#include <vector>


enum class EntityKind
{
	NONE = 0,
	PLAYER,
	ROCKS,
	COINS,
};



struct EntityDescription
{
	Color color = RAYWHITE;
};


class Entity
{
public:
	//EntityDescription* desc;

	EntityKind kind;
	Vector2i Position;
};




class Level
{
public:
	void render();
	Vector2i CreateMovementVector();
	void MovePlayer(Vector2i CreateMovementVector);

	void update();

	
	std::vector<Vector2i> Rocks;
	std::vector<Entity> entities{ Entity{EntityKind{EntityKind::PLAYER} , Vector2i{40,40} } };

};
