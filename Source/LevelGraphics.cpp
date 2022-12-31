#include "Entity.h"

void Level::render()
{
	for (auto& e : entities)
	{
		switch (e.kind)
		{
		case(EntityKind::PLAYER):
			DrawRectangle(e.Position.x *10, e.Position.y * 10, 40, 40, RED);

			break;

		case(EntityKind::LASER):

			DrawRectangle(e.Position.x * 10, e.Position.y * 10, 20, 20, ORANGE);
			break;

		case(EntityKind::ROCKS):

			DrawRectangle(e.Position.x * 10, e.Position.y * 10, 40, 40, GRAY);
			break;
		}
		

	}
	
}