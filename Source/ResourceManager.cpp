#include "ResourceManager.h"

void ResourceManager::LoadResources()
{
     texture.Ship = LoadTexture("./Resources/Textures/Ship.png");
     texture.Rocks = LoadTexture("./Resources/Textures/Rock.png");
     texture.Laser = LoadTexture("./Resources/Textures/Laser.png");
     texture.Coins = LoadTexture("./Resources/Textures/Coin.png");
}