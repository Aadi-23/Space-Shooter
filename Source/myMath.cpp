#include "myMath.h"
#include <cmath>


float Math::random_float_01()
{
	return rand() / static_cast<float>(RAND_MAX);
}

Vector2 Math::random_direction()
{
	float angle = random_float_01() * 2 * PI;
	return Vector2{ cosf(angle),sinf(angle) };
}

bool Math::Check_For_Collision(Vector2i FirstObjectPos, Vector2i SecondObjectPos, int Radius_1, int Radius_2)
{
	int a = static_cast<int>(Radius_1 + Radius_2);
	int y = abs(FirstObjectPos.x - SecondObjectPos.x);
	int h = abs(FirstObjectPos.y - SecondObjectPos.y);

	if ((a ^ 2) >= (y ^ 2) + (h ^ 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}