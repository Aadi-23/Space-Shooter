#include "raylib.h"

struct Textures
{
	Texture2D Ship;
};


class ResourceManager
{
public:
	Textures texture;
	void LoadResources();
};
