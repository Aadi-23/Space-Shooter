#include "ResourceManager.h"

Textures ResourceManager::texture;
Sounds ResourceManager::sound;
void ResourceManager::LoadResources()
{
     texture.Ship = LoadTexture("./Resources/Textures/Ship.png");
     texture.Rocks = LoadTexture("./Resources/Textures/Rock.png");
     texture.Laser = LoadTexture("./Resources/Textures/Laser.png");
     texture.Coins = LoadTexture("./Resources/Textures/Coin.png");
     texture.ShipAnim1 = LoadTexture("./Resources/Textures/Ship_Anim_1.png");
     texture.ShipAnim2 = LoadTexture("./Resources/Textures/Ship_Anim_2.png");


     sound.RockBlast = LoadSound("./Resources/Sounds/RockBlast.wav");
     sound.CoinCollect = LoadSound("./Resources/Sounds/Coin_Collect.wav");
     sound.LaserShoot = LoadSound("./Resources/Sounds/LaserShoot.wav");
     //sound.ShipExplosion = LoadSound("./Resources/Sounds/ShipExplosion.wav");
}

void ResourceManager::UnloadResources()
{
    UnloadTexture(texture.Ship);
    UnloadTexture(texture.Rocks);
    UnloadTexture(texture.Laser);
    UnloadTexture(texture.Coins);
    UnloadTexture(texture.ShipAnim1);
    UnloadTexture(texture.ShipAnim2);

    UnloadSound(sound.RockBlast);
    UnloadSound(sound.CoinCollect);
    UnloadSound(sound.LaserShoot);


}