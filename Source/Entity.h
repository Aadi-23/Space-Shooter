


enum class EntityKind
{
	NONE = 0,
	SHIP,
	LASER,
	ROCKS,
	COINS,
	PARTICLES,
	SMASHED_PARTICLES
};
;


class Entity
{
public:
	
	EntityKind kind = {};
	Vector2i Position = { 0,0 };

	float Radius = 0;

	bool dead = false;
};





