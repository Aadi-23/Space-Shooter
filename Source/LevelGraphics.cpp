#include "GameLevel.h"

void Level::render()
{
	for (auto& e : entities)
	{
		switch (e.kind)
		{
		case(EntityKind::PLAYER):
			DrawRectangle(e.Position.x * 10, e.Position.y * 10, 40, 40, RED);

			break;
		}
	}
}