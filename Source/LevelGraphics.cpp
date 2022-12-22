#include "Entity.h"
#include "GameLevel.h"

void Level::render()
{
	Entity entities;
	DrawRectangle(entities.Position.x, entities.Position.y, 40, 40, entities.desc->color);
}