#pragma once
#include "raylib.h"
#include "tetromino.h"

struct Tetromino_controller
{
    Vector2 pos = { 4,1 };
    Vector2 input = { 0,0 };
    int rotation_input = 0;
    int piece_grid_side = 4;
    int rotation_index = 0;
    Color piece_color;

    Tetromino shapes;

    enum PIECES
    {
        NO_PIECE, //not to happen during game
        L,
        I,
        T,
        J,
        S,
        Z,
        O
    };

    PIECES current_piece = NO_PIECE;
    PIECES next_piece = NO_PIECE;

    int next_grid[16] = { 0,0,0,0,
                          0,0,0,0,
                          0,0,0,0,
                          0,0,0,0, };

    int reference_grid[16] = {0,0,0,0,
                              0,0,0,0,
                              0,0,0,0,
                              0,0,0,0, };

    int current_grid[16] = { 0,0,0,0,
                             0,0,0,0,
                             0,0,0,0,
                             0,0,0,0, };

    void piece_rotation();
    void change_piece(int new_piece[16], PIECES new_current_piece);

    void random_piece();

    void update();
    void render(Vector2 level_pos);
};