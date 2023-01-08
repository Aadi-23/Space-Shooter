#include "raylib.h"

struct Textures
{
	Texture2D Ship;
	Texture2D Rocks;
	Texture2D Laser;
	Texture2D Coins;
	Texture2D ShipAnim1;
	Texture2D ShipAnim2;
};

struct Sounds
{
	Sound RockBlast;
};


class ResourceManager
{
public:
	Textures texture;
	Sounds sound;
	void LoadResources();
	void UnloadResources();
};
