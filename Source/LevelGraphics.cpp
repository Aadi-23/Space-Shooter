#include "GameLevel.h"

void Level::render(Entity & entities)
{
	DrawRectangle(entities.Position.x*10, entities.Position.y*10, 40, 40, RAYWHITE);
}