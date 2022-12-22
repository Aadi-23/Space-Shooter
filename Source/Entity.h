#include "myMath.h"


struct EntityDescription
{
	Color color = RAYWHITE;
};


class Entity
{
public:
	EntityDescription* desc;
	Vector2i Position;
};
