#include "raylib.h"
#include <iostream>
#include "level.h"
#include "file.h"


int main(void)
{    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 810;
    const int screenHeight = 900;
    Level level;

    InitWindow(screenWidth, screenHeight, "Tetris");

    SetTargetFPS(60);              

    //--------------------------------------------------------------------------------------

    InitAudioDevice();

    auto sound = LoadSound("./hitHurt.ogg");
    level.init();
    File_Manager file;
    file.write("Anteeksi, olen Ganondorf");

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        level.update();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        level.render();

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