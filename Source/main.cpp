/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*b
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Level.h"


typedef enum GameManager { TitleScreen = 0, GameScreen, GameEndScreen }GameManager;


int main(void)
{    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 600;
    const int screenHeight = 580;


    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
    
    InitAudioDevice();

    GameManager currentscreen = TitleScreen;
    Level gamelevel;
    ResourceManager resources;

    resources.LoadResources();
    gamelevel.spawn_ship();
  

    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        switch (currentscreen)
        {
        case TitleScreen:
        {
            BeginDrawing();

            ClearBackground(GRAY);

            DrawText("Shoot Rock", 180, 100, 50, LIGHTGRAY);
            DrawText("Game By 'Adarsh'", 210, 200, 25, RED);
            DrawText("Press ENTER to Start", 100, 350, 40, RAYWHITE);

            EndDrawing();

            if (IsKeyPressed(KEY_ENTER))
            {
                currentscreen = GameScreen;
            }
            break;
        }
        

        case GameScreen:
        {
            BeginDrawing();

            ClearBackground(BLACK);

            

            gamelevel.render(resources.texture);

            gamelevel.update();

            
            EndDrawing();

            if (gamelevel.ShipCollided == true)
            {
                currentscreen = GameEndScreen;
               
                
            }


            break;
        }
        case(GameEndScreen):
        {
            BeginDrawing();

            ClearBackground(BLACK);

            DrawText(TextFormat("Score : %i", gamelevel.score), 220, 200, 40, WHITE);
            DrawText("Press R to Go to HomeScreen", 90, 300, 30, RAYWHITE);
            if (IsKeyPressed(KEY_R))
            {
                currentscreen = TitleScreen;
                gamelevel.ResetLevel();
            }

            EndDrawing();
        }
 
        }
    }

    CloseAudioDevice();
    
    resources.UnloadResources();

   
    CloseWindow();        // Close window and OpenGL context
  

    return 0;
}