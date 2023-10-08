#include "tetromino_controller.h"

void Tetronimo_controller::update()
{
    input = { 0,0 };
    rotation_input = 0;

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
    if (IsKeyPressed(KEY_C))
    {
        rotation_input = 1;
    }
}

void Tetronimo_controller::render(Vector2 level_pos)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (current_grid[j + i * 4] == 1)
                DrawRectangle(( (int)pos.x * 50 ) + (j * 50) + (int)level_pos.x, ((int)pos.y * 50) + (i * 50) + (int)level_pos.y, 50, 50, RED);
        }
    }

}

void Tetronimo_controller::piece_rotation()
{
    //Move back to tetromino controller
    int orientation = 0;

    if (current_piece == L ||
        current_piece == J ||
        current_piece == T)
    {
        orientation = rotation_index % 4;
    }
    if (current_piece == I ||
        current_piece == S ||
        current_piece == Z)
    {
        orientation = rotation_index % 2;
    }
    if (current_piece == O)
    {
        orientation = 3;
    }


    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            switch (orientation)
            {
            case(0):
                //90 degrees
                current_grid[(x)+(y) * 4] = reference_grid[(3 - y) + (x * 4)];

                break;
            case(1):
                //180 degrees
                current_grid[(x)+(y) * 4] = reference_grid[15 - (x + (y * 4))];
                break;
            case(2):
                //270 degrees
                current_grid[(x)+(y) * 4] = reference_grid[(12 + y) - (x) * 4];
                break;
            case(3):
                //360 degrees
                current_grid[x + (y * 4)] = reference_grid[x + (y * 4)];
                break;
            }
        }
    }
    rotation_index++;
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
                reference_grid[j + i * piece_grid_side] = shapes.grid_I[j + i * piece_grid_side];
                current_piece = I;
            }
        }
        break;
    case(J):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_J[j + i * piece_grid_side];
                reference_grid[j + i * piece_grid_side] = shapes.grid_J[j + i * piece_grid_side];
                current_piece = J;
            }
        }
        break;
    case(L):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_L[j + i * piece_grid_side];
                reference_grid[j + i * piece_grid_side] = shapes.grid_L[j + i * piece_grid_side];
                current_piece = L;
            }
        }
        break;
    case(S):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_S[j + i * piece_grid_side];
                reference_grid[j + i * piece_grid_side] = shapes.grid_S[j + i * piece_grid_side];
                current_piece = S;
            }
        }
        break;
    case(Z):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_Z[j + i * piece_grid_side];
                reference_grid[j + i * piece_grid_side] = shapes.grid_Z[j + i * piece_grid_side];
                current_piece = Z;
            }
        }
        break;
    case(O):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_O[j + i * piece_grid_side];
                reference_grid[j + i * piece_grid_side] = shapes.grid_O[j + i * piece_grid_side];
                current_piece = O;
            }
        }
        break;
    case(T):
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = shapes.grid_T[j + i * piece_grid_side];
                reference_grid[j + i * piece_grid_side] = shapes.grid_T[j + i * piece_grid_side];
                current_piece = T;
            }
        }
        break;

    }
}