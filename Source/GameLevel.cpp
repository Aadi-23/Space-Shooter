#include <vector>
#include "myMath.h"
#include "GameLevel.h"




Vector2i Level::CreateMovementVector()
{
	int LRMV = IsKeyPressed(KEY_RIGHT) - IsKeyPressed(KEY_LEFT);
	int UDMV = IsKeyPressed(KEY_DOWN) - IsKeyPressed(KEY_UP);

	return Vector2i(LRMV, UDMV);
}

void Level::MovePlayer(Vector2i CreateMovementVector, Entity* e)
{
	Vector2i FuturePosition = e->Position + CreateMovementVector;


	e->Position = FuturePosition;
}
