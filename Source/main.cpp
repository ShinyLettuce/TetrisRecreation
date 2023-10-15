#include "raylib.h"
//#include <iostream>
//#include "level.h"
#include "game_state.h"
#include "file.h"


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

    Game_State game;
    game.game_state.push(Game_State::GAME_STATE::MAIN_MENU);

    game.hills = LoadTexture("paralHills.png"); // make media & media init later
    game.hills2 = game.hills;
    game.sky = LoadTexture("paralsky.png");
    game.car = LoadTexture("paralCar.png");
    game.clouds = LoadTexture("paralCloud.png");
    game.clouds2 = game.clouds;
    game.lake = LoadTexture("paralLake.png");
    game.pole = LoadTexture("paralPole.png");
    game.title = LoadTexture("paralTitle.png");

    File_Manager file;
    file.write("Anteeksi, olen Ganondorf");

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