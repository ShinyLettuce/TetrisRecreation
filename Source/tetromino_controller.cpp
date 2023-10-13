#include "tetromino_controller.h"


void Tetromino_controller::piece_rotation()
{
    int orientation = 0;

    rotation_index += (1 * rotation_input);

    if (current_piece == PIECES::L ||
        current_piece == PIECES::J ||
        current_piece == PIECES::T)
    {
        orientation = wrap_index(rotation_index, 4);
    }
    if (current_piece == PIECES::I ||
        current_piece == PIECES::S ||
        current_piece == PIECES::Z)
    {
        orientation = wrap_index(rotation_index, 2);
    }
    if (current_piece == PIECES::O)
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
                //360 degrees
                current_grid[x + (y * 4)] = reference_grid[x + (y * 4)];
                break;
            case(1):
                //90 degrees
                current_grid[(x)+(y) * 4] = reference_grid[(3 - y) + (x * 4)];    
                break;
            case(2):
                //180 degrees
                current_grid[(x)+(y) * 4] = reference_grid[15 - (x + (y * 4))];
                break;
            case(3):
                //270 degrees
                current_grid[(x)+(y) * 4] = reference_grid[(12 + y) - (x) * 4];
                break;
            default:
                break;
            }
        }
    }

    //piece correction
    if (current_piece == PIECES::S)
    {
        if (orientation == 0)
        {
            pos.y++;
        }
        else
        {
            pos.y--;
        }
    }
    if (current_piece == PIECES::Z)
    {
        if (orientation == 0)
        {
            pos.x++;
        }
        else
        {
            pos.x--;
        }
    }
    
    if ((current_piece == PIECES::L || current_piece == PIECES::J || current_piece == PIECES::T) && rotation_input == 1)
    {
        if (orientation == 0)
        {
            pos.x++;
        }
        else if(orientation == 1)
        {
            pos.y--;
        }
        else if (orientation == 2)
        {
            pos.x--;
        }
        else if (orientation == 3)
        {
            pos.y++;
        }
    }
    if ((current_piece == PIECES::L || current_piece == PIECES::J || current_piece == PIECES::T) && rotation_input == -1)
    {
        if (orientation == 0)
        {
            pos.y++;
        }
        else if (orientation == 1)
        {
            pos.x++;
        }
        else if (orientation == 2)
        {
            pos.y--;
        }
        else if (orientation == 3)
        {
            pos.x--;
        }
    }
}

void Tetromino_controller::change_piece(int new_piece[16], PIECES new_current_piece)
{
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                current_grid[j + i * piece_grid_side] = new_piece[j + i * piece_grid_side];
                reference_grid[j + i * piece_grid_side] = new_piece[j + i * piece_grid_side];

            }
        }
        current_piece = new_current_piece;
}

void Tetromino_controller::random_piece()
{
    int* temp = nullptr; // change name or something

    switch (GetRandomValue(1, 7))
    {
    case(1):    
        next_piece = PIECES::S;
        temp = shapes.grid_S;
        break;
    case(2):    
        next_piece = PIECES::I;
        temp = shapes.grid_I;
        break;
    case(3):    
        next_piece = PIECES::Z;
        temp = shapes.grid_Z;
        break;
    case(4):    
        next_piece = PIECES::J;
        temp = shapes.grid_J;
        break;
    case(5):    
        next_piece = PIECES::O;
        temp = shapes.grid_O;
        break;
    case(6):    
        next_piece = PIECES::T;
        temp = shapes.grid_T;
        break;
    case(7):    
        next_piece = PIECES::L;
        temp = shapes.grid_L;
        break;
    default:
        break;
    }

    if (temp != nullptr)
    {
        for (int i = 0; i < piece_grid_side; i++)
        {
            for (int j = 0; j < piece_grid_side; j++)
            {
                next_grid[j + i * piece_grid_side] = temp[j + i * piece_grid_side];
            }
        }
    }

}

void Tetromino_controller::update()
{
    input = { 0,0 };            //After lockdown, force player to click down again
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
    if (IsKeyPressed(KEY_X))
    {
        rotation_input = -1;
    }
}

void Tetromino_controller::render(Vector2 level_pos)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            switch (current_grid[j + i * 4])
            {
            case(0):    piece_color = WHITE;
                break;
            case(1):    piece_color = GRAY;
                break;
            case(2):    piece_color = BLUE;
                break;
            case(3):    piece_color = RED;
                break;
            case(4):    piece_color = YELLOW;
                break;
            case(5):    piece_color = GREEN;
                break;
            case(6):    piece_color = PURPLE;
                break;
            case(7):    piece_color = DARKBLUE;
                break;
            case(8):    piece_color = ORANGE;
                break;
            default:
                break;
            }
            if (current_grid[j + i * 4] != 0)
            {
                DrawRectangle(( static_cast<int>(pos.x) * 50 ) + (j * 50) + static_cast<int>(level_pos.x), (static_cast<int>(pos.y) * 50) + (i * 50) + static_cast<int>(level_pos.y), 50, 50, piece_color);
            }
        }
    }
}