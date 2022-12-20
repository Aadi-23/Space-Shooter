#include <vector>
#include "myMath.h"




Vector2i CreateMovementVector()
{
	int LRMV = IsKeyPressed(KEY_RIGHT) - IsKeyPressed(KEY_LEFT);
	int UDMV = IsKeyPressed(KEY_DOWN) - IsKeyPressed(KEY_UP);

	return Vector2i(LRMV, UDMV);
}