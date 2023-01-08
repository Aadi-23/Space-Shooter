#include "ResourceManager.h"

void ResourceManager::LoadResources()
{
     texture.Ship = LoadTexture("./Resources/Textures/Ship.png");
     texture.Rocks = LoadTexture("./Resources/Textures/Rock.png");
     texture.Laser = LoadTexture("./Resources/Textures/Laser.png");
     texture.Coins = LoadTexture("./Resources/Textures/Coin.png");
     texture.ShipAnim1 = LoadTexture("./Resources/Textures/Ship_Anim_1.png");
     texture.ShipAnim2 = LoadTexture("./Resources/Textures/Ship_Anim_2.png");


     sound.RockBlast = LoadSound("./Resources/Sounds/RockBlast.wav");
}

void ResourceManager::UnloadResources()
{
    UnloadTexture(texture.Ship);
    UnloadTexture(texture.Rocks);
    UnloadTexture(texture.Laser);
    UnloadTexture(texture.Coins);
    UnloadTexture(texture.ShipAnim1);
    UnloadTexture(texture.ShipAnim2);



}