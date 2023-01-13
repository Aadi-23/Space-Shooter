#include "raylib.h"

struct Textures   // I declare all the texture in this struct
{
	Texture2D Ship;
	Texture2D Rocks;
	Texture2D Laser;
	Texture2D Coins;
	Texture2D LaserAnim0;
	Texture2D ShipAnim1;
	Texture2D ShipAnim2;
	Texture2D SmashedParticles;
};

struct Sounds   // All sounds of the game
{
	Sound RockBlast;
	Sound CoinCollect;
	Sound LaserShoot;
	Sound LaserCharge;
	Sound ShipExplosion;
};


class ResourceManager   // I made a class So I can handle all the resources and use in in other places of code
{
public:
	static Textures texture;
	static Sounds sound;
	static void LoadResources();
	static void UnloadResources();
};
