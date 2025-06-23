#include "raylib.h"
#include "game_state.h"
#include <fstream>

int main(void)
{    
    const int screenWidth = 810;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Tetris");

    SetTargetFPS(60);              

    InitAudioDevice();
    auto sound = LoadSound("./hitHurt.ogg");
    Media::media_init();

    Game_State game;

    High_Score_Entry h;
    FILE* fp_input;
    errno_t errt;
    errt = fopen_s(&fp_input, ".\\Assets\\text\\highscore.bin", "rb");
    if (errt != 0)
    {
    }
    else
    {
        
        while (!feof(fp_input))
        {
            fread(&h.name, sizeof(h.name), 1, fp_input);
            fread(&h.score, sizeof(h.score), 1, fp_input);
            game.high_score.list.push_back(h);
        }
        fclose(fp_input);
    }

    game.game_state.push(Game_State::GAME_STATE::MAIN_MENU);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK); // move somewhere else

        game.update();

        EndDrawing();
    }

    for (High_Score_Entry test : game.high_score.list)
    {
        std::cout << test.name;
        std::cout << test.score;
    }

    CloseAudioDevice();
    Media::media_unload();
    FILE* fp_output;
    errno_t err;
    err = fopen_s(&fp_output,".\\Assets\\text\\highscore.bin", "wb");
    if (err != 0)
    {
    }
    else
    {
        for(High_Score_Entry saved : game.high_score.list)
        {
            fwrite(&saved, sizeof(saved), 1, fp_output);
        }
        fclose(fp_output);
    }

    CloseWindow();

    return 0;
}