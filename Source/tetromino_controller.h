#pragma once
#include "raylib.h"
#include "tetromino.h"

struct Tetronimo_controller
{
    Vector2 pos = { 2,0 };
    Vector2 input = { 0,0 };
    int rotation_input = 0;
    int piece_grid_side = 4;
    int rotation_index = 0;

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

    int reference_grid[16] = {0,0,0,0,
                              0,0,0,0,
                              0,0,0,0,
                              0,0,0,0, };

    int current_grid[16] = { 0,0,0,0,
                             0,0,0,0,
                             0,0,0,0,
                             0,0,0,0, };

    void piece_rotation();
    void change_piece(PIECES new_piece);

    void update();
    void render();
};