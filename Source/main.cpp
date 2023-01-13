#include "raylib.h"
#include "Game.h"


//typedef enum GameManager {GameScreen, GameEndScreen }GameManager;


int main(void)
{    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 600;
    const int screenHeight = 580;


    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
    
    SetExitKey(0);

    InitAudioDevice();
    Game game;

    ResourceManager::LoadResources();
    game.level.spawn_ship();
    
    game.states.push(State::MAIN_MENU);

    game.level.screen_shake_camera;
    game.level.screen_shake_camera.zoom = 1.f;
   /* game.level.screen_shake_camera.offset = (Vector2)(GetRenderWidth() / 2, GetRenderHeight() / 2);
    game.level.screen_shake_camera.target = static_cast<Vector2>(0,0);*/
    
    while (game.Isrunning)   // Runs the game loop as long as the bool is true
    {


        if (WindowShouldClose())
        {
            game.Isrunning = false;
        }

        State Current_state = game.states.top();
        switch (Current_state)
        {
        case State::MAIN_MENU:
        {
            BeginDrawing();

            ClearBackground(GRAY);

            DrawText("Shoot Rock", 150, 60, 50, LIGHTGRAY);
            DrawText("Game By 'Adarsh'", 200, 120, 25, RED);

            game.Do_mainmenu_frame();

            EndDrawing();
            break;
        }


        case State::GAME:
        {
            BeginDrawing();

            ClearBackground(BLACK);

            game.level.render(ResourceManager::texture);

            game.level.update();

            EndDrawing();

            if (IsKeyPressed(KEY_ESCAPE))    // Pops the menu screen when press escape
            {

                game.states.push(State::MENUWHILEGAME);

            }

            if (game.level.ShipCollided == true)  // Go to end screen when ship crashes
            {
                game.ShipIndex--;
                if (game.ShipIndex <= 0)
                {
                    game.states.pop();
                    game.states.push(State::ENDSCREEN);

                }
            }
            if (game.level.score >= 10000)
            {
                game.states.pop();
                game.states.push(State::WINSCREEN);
            }
        }
        break;

        case(State::ENDSCREEN):
        {

            BeginDrawing();

            ClearBackground(BLACK);

            DrawText(TextFormat("Score : %i", game.level.score), 220, 200, 40, WHITE);
            DrawText("Press R to Go to MainMenu", 90, 300, 30, RAYWHITE);

            EndDrawing();
            if (IsKeyPressed(KEY_R))
            {
                game.states.pop();
                game.ShipIndex = 30;
                game.level.ResetLevel();
            }
        }
        break;



        case(State::WINSCREEN):
        {
            BeginDrawing();
            ClearBackground(BLACK);

            DrawText("YOU WON!", 200, 120, 40, BLUE);
            DrawText(TextFormat("Score : %i", game.level.score), 195, 200, 40, RAYWHITE);
            DrawText("Press ESC to Go to MainMenu", 90, 300, 30, RAYWHITE);

            EndDrawing();

            if (IsKeyPressed(KEY_ESCAPE))
            {
                game.states.pop();
                game.ShipIndex = 30;
                game.level.ResetLevel();
                
            }
        }
        break;


        case(State::MENUWHILEGAME):
        {
            BeginDrawing();
            ClearBackground(BLACK);
            game.Menu_While_Game();

            EndDrawing();
        }
        break;

        case(State::CONTROLS):
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("CONTROLS", 200, 160, 35, WHITE);
            DrawText("Arrow Keys -> Ship Movement", 110, 220, 25, ORANGE);
            DrawText("Hold 'Z' -> Charge Laser", 150, 250, 25, ORANGE);
            DrawText("Release 'Z' -> Fire Laser", 150, 280, 25, ORANGE);
            DrawText("Press ESC for MAINMENU", 140, 350, 25, BLUE);
            DrawText("WIN - Score: 10000", 160, 100, 35, YELLOW);
            EndDrawing();

            if (IsKeyPressed(KEY_ESCAPE))
            {
                game.states.pop();
            }
        }
        break;
        }
        
    }

    CloseAudioDevice();
    
    ResourceManager::UnloadResources();

   
    CloseWindow();        // Close window and OpenGL context
  

    return 0;
}