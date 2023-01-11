
// I made this enum class So I can assign types to entites and store their identity which i can access later

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


// This entity class i maded to keep all characterstics which any entity in game will have.
class Entity
{
public:
	
	EntityKind kind = {};
	Vector2i Position = { 0,0 };
	Vector2 Direction = { 0,0 };

	float Radius = 0;

	bool dead = false;
};





