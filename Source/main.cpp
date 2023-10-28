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

    std::fstream score_list(".\\Assets\\text\\highscore.txt");
    while (!score_list.eof())
    {
        High_Score_Entry h;
        score_list >> h.name;
        score_list >> h.score;
        game.high_score.list.push_back(h);
        if (score_list.eof()) break;
    }
    score_list.close();

    for (High_Score_Entry e : game.high_score.list)
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
    for(High_Score_Entry h : game.high_score.list)
    {
        score_list << h.name;
        score_list << h.score;
    }
    score_list.close();

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}