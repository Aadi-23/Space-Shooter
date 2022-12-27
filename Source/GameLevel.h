#include "Entity.h"
#include <vector>

class Level
{
public:
	void render();
	Vector2i CreateMovementVector();
	void MovePlayer(Vector2i CreateMovementVector, Level*level);

	void update();

	Vector2i PlayerPos;
	std::vector<Vector2i> Rocks;
	std::vector<Entity> entities{ Entity{EntityKind{EntityKind::PLAYER} , Vector2i{40,40} } };

};
