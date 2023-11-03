#pragma once
#include "raylib.h"
#include "tetromino.h"
#include "math_util.h"

struct Tetromino_controller
{
    Color piece_color = WHITE;
    Color next_piece_color = WHITE;
    Vector2 pos = { 4,1 };
    const int segment_pixel_side = 50;
    const int piece_grid_side = 4;

    Vector2 input = { 0,0 };
    int rotation_input = 0;
    int rotation_index = 0;
    int x_movement_speed = 23;
    Tetromino shapes;

    enum class PIECES
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

    PIECES current_piece = PIECES::NO_PIECE;
    PIECES next_piece = PIECES::NO_PIECE;

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
    void render(Vector2 level_grid_pos, int cell_pixel_side);
};