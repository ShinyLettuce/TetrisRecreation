#include "tetromino_controller.h"

void Tetronimo_controller::update()
{
    input = { 0,0 };

    if (IsKeyDown(KEY_LEFT))
    {
        input.x -= 1;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        input.x += 1;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        input.y += 1;
    }
    if (IsKeyDown(KEY_C))
    {
    //    rotate();
        change_piece(L);
    }
}

void Tetronimo_controller::render()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (current_grid[j + i * 4] == 1)
                DrawRectangle(((int)pos.x * 50) + (j * 50), ((int)pos.y * 50) + (i * 50), 50, 50, RED);
        }
    }

}

void Tetronimo_controller::change_piece(PIECES new_piece)
{
    //OPTIMIZE

    switch (new_piece)
    {
    case(I):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_I[j + i * piece_grid_side];
            }
        }
        break;
    case(J):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_J[j + i * piece_grid_side];
            }
        }
        break;
    case(L):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_L[j + i * piece_grid_side];
            }
        }
        break;
    case(S):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_S[j + i * piece_grid_side];
            }
        }
        break;
    case(Z):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_Z[j + i * piece_grid_side];
            }
        }
        break;
    case(O):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_O[j + i * piece_grid_side];
            }
        }
        break;
    case(T):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_T[j + i * piece_grid_side];
            }
        }
        break;

    }
}