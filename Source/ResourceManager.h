#include "raylib.h"

struct Textures
{
	Texture2D Ship;
	Texture2D Rocks;
	Texture2D Laser;
	Texture2D Coins;
};


class ResourceManager
{
public:
	Textures texture;
	void LoadResources();
};
