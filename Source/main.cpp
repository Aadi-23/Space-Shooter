#include "raylib.h"
#include "Level.h"
#include "Menu.h"


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

    enum struct GameManager{GAMESCREEN, ENDSCREEN};
    GameManager currentscreen = GameManager::GAMESCREEN;
    Level gamelevel;
    Game game;

    ResourceManager::LoadResources();
    gamelevel.spawn_ship();
    
    game.states.push(State::MAIN_MENU);
    
    while (game.Isrunning)    // Detect window close button or ESC key
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

            switch (currentscreen)
            {

            case(GameManager::GAMESCREEN):
                {
                BeginDrawing();

                ClearBackground(BLACK);



                gamelevel.render(ResourceManager::texture);

                gamelevel.update();

                if (IsKeyPressed(KEY_ESCAPE))
                {
                    game.states.pop();

                }


                EndDrawing();

                if (gamelevel.ShipCollided == true)
                {
                    currentscreen = GameManager::ENDSCREEN;

                }
                }
                break;



            case(GameManager::ENDSCREEN):
            {
                
                BeginDrawing();

                ClearBackground(BLACK);

                DrawText(TextFormat("Score : %i", gamelevel.score), 220, 200, 40, WHITE);
                DrawText("Press R to Go to MainMenu", 90, 300, 30, RAYWHITE);

                EndDrawing();
                if (IsKeyPressed(KEY_R))
                {
                    game.states.pop();
                    
                    gamelevel.ResetLevel();
                    currentscreen = GameManager::GAMESCREEN;

                }
            }
            break;
            
            }     
            break;
        }
  
 
        }
    }

    CloseAudioDevice();
    
    ResourceManager::UnloadResources();

   
    CloseWindow();        // Close window and OpenGL context
  

    return 0;
}