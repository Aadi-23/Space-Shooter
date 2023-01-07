


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





