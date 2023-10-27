#include "raylib.h"
#include "game_state.h"


int main(void)
{    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 810;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Tetris");

    SetTargetFPS(60);              

    //--------------------------------------------------------------------------------------

    InitAudioDevice();
    auto sound = LoadSound("./hitHurt.ogg");
    Media::media_init();

    Game_State game;
    game.game_state.push(Game_State::GAME_STATE::MAIN_MENU);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();
        ClearBackground(BLACK); // move somewhere else

        game.update();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseAudioDevice();
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}