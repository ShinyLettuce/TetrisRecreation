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

    //std::fstream score_list(".\\Assets\\text\\highscore.txt");
    High_Score_Entry h;
    //while (score_list >> h.name >> h.score)
    //{
    //    game.high_score.list.push_back(h);
    //}
    //score_list.close();

    FILE* fp_input;
    errno_t errt;
    //score_list.open(".\\Assets\\text\\highscore.txt");
    errt = fopen_s(&fp_input, ".\\Assets\\text\\highscore.bin", "rb");
    if (errt != 0)
    {
        //nothing
    }
    else
    {
        
        while (!feof(fp_input))
        {
            fread(&h.name, sizeof(h.name), 1, fp_input);
            fread(&h.score, sizeof(h.score), 1, fp_input);
            game.high_score.list.push_back(h);
        }
        
    }
    fclose(fp_input);

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
    FILE* fp_output;
    errno_t err;
    //score_list.open(".\\Assets\\text\\highscore.txt");
    err = fopen_s(&fp_output,".\\Assets\\text\\highscore.bin", "wb");
    if (err != 0)
    {
        //nothing
    }
    else
    {
        for(High_Score_Entry saved : game.high_score.list)
        {
             //score_list << saved.name;
             //score_list << saved.score;

            fwrite(&saved, sizeof(saved), 1, fp_output);
        }
    }
    //score_list.close();

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}