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
#include "Entity.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

typedef enum GameManager { TitleScreen = 0, GameScreen }GameManager;


int main(void)
{    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;


    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    GameManager currentscreen = TitleScreen;
    Level gamelevel;
    gamelevel.spawn_ship();
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------

        
        switch (currentscreen)
        {
        case TitleScreen:
        {
            BeginDrawing();

            ClearBackground(GRAY);

            DrawText("Shoot Rock", 260, 100, 50, LIGHTGRAY);
            DrawText("Game By 'Adarsh'", 300, 200, 25, RED);
            DrawText("Press ENTER to Start", 200, 350, 40, RAYWHITE);

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

            

            gamelevel.render();

            gamelevel.update();

            

            EndDrawing();

            if (gamelevel.ShipCollided == true)
            {
                currentscreen = TitleScreen;
                gamelevel.ShipCollided = false;
            }

            break;
        }
 
        }
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}