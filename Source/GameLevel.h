#include "Entity.h"
#include <vector>

class Level
{
public:
	void render(Entity& entities);
	Vector2i CreateMovementVector();
	void MovePlayer(Vector2i CreateMovementVector, Entity *e);
};
