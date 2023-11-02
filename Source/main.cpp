#include "raylib.h"
#include "game_state.h"
#include <fstream>

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

    std::fstream score_list(".\\Assets\\text\\highscore.txt");
    
    High_Score_Entry h;
    while (score_list >> h.name >> h.score)
    {
        game.high_score.list.push_back(h);
    }
    score_list.close();

    for (High_Score_Entry e : game.high_score.list) // remember to remove
    {
        std::cout << e.name;
        std::cout << e.score;
    }

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
    Media::media_unload();
    
    score_list.open(".\\Assets\\text\\highscore.txt");
    for(High_Score_Entry saved : game.high_score.list)
    {
        score_list << saved.name;
        score_list << saved.score;
    }
    score_list.close();

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}