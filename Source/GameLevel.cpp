#include "myMath.h"
#include "GameLevel.h"




Vector2i Level::CreateMovementVector()
{
	int LRMV = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
	int UDMV = IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);

	return Vector2i(LRMV, UDMV);
}

void Level::MovePlayer(Vector2i CreateMovementVector, Entity* e)
{
	Vector2i FuturePosition = e->Position + CreateMovementVector;


	e->Position = FuturePosition;
}
