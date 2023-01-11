#include "raylib.h"
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

    enum struct GameManager{GAMESCREEN, ENDSCREEN};     // I made this enum struct So I can switch to a end screen from game screen while being in a particular state
    GameManager currentscreen = GameManager::GAMESCREEN;
    Level gamelevel;
    Game game;

    ResourceManager::LoadResources();
    gamelevel.spawn_ship();
    
    game.states.push(State::MAIN_MENU);
    
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

            switch (currentscreen)
            {

            case(GameManager::GAMESCREEN):
                {
                BeginDrawing();

                ClearBackground(BLACK);



                gamelevel.render(ResourceManager::texture);

                gamelevel.update();

                if (IsKeyPressed(KEY_ESCAPE))    // Pops the menu screen when press escape
                {
                    game.states.pop();
                    game.states.push(State::MENUWHILEGAME);

                }


                EndDrawing();

                if (gamelevel.ShipCollided == true)  // Go to end screen when ship crashes
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

        case(State::MENUWHILEGAME):
        {
            BeginDrawing();
            ClearBackground(BLACK);
            game.Menu_While_Game();

            EndDrawing();
        }
        break;

        case(State::OPTIONS):
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("SORRY! NO OPTION FOR NOW.", 100, 250, 30, ORANGE);
            DrawText("Press ESC", 200, 300, 30, ORANGE);
            EndDrawing();
            
            if (IsKeyPressed(KEY_ESCAPE))
            {
                game.states.pop();
            }
        }
        }
        }
    }

    CloseAudioDevice();
    
    ResourceManager::UnloadResources();

   
    CloseWindow();        // Close window and OpenGL context
  

    return 0;
}