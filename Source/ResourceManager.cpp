#include "ResourceManager.h"

Textures ResourceManager::texture;                     // I made my texture and sound static function in my header files So I defined them here
Sounds ResourceManager::sound;

void ResourceManager::LoadResources()                 //Load resources function I use for loading all the texture and sounds for the game
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

void ResourceManager::UnloadResources()                // I made this function which unloads all reasources and I can call it at the end before closing window So I don't leak memory..
{
    // Unloading the textures
    UnloadTexture(texture.Ship);
    UnloadTexture(texture.Rocks);
    UnloadTexture(texture.Laser);
    UnloadTexture(texture.Coins);
    UnloadTexture(texture.ShipAnim1);
    UnloadTexture(texture.ShipAnim2);

    //Unloading the sounds
    UnloadSound(sound.RockBlast);
    UnloadSound(sound.CoinCollect);
    UnloadSound(sound.LaserShoot);


}