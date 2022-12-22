#include "Entity.h"

class Level
{
public:
	void render();
	Vector2i CreateMovementVector();
	void MovePlayer(Vector2i CreateMovementVector, Entity *e);
};
