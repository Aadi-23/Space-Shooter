#include "myMath.h"


enum class EntityKind
{
	NONE = 0,
	PLAYER,
	ROCKS,
	COINS,
};

class Level;

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