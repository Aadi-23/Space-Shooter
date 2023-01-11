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
	Sound CoinCollect;
	Sound LaserShoot;
	Sound LaserCharge;
	Sound ShipExplosion;
};


class ResourceManager
{
public:
	static Textures texture;
	static Sounds sound;
	static void LoadResources();
	static void UnloadResources();
};
