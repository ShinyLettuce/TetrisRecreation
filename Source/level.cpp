#include "level.h"

void Level::init()
{
    hello.random_piece();
    hello.change_piece(hello.next_grid, hello.next_piece);
    hello.random_piece();

}

bool Level::piece_collision(int future_pos_x, int pos_y)
{
    if (falling)
    {
        pos_y++;
    }

    for (int i = 0; i < hello.piece_grid_side; i++)
    {
        for (int j = 0; j < hello.piece_grid_side; j++)
        {
            if (hello.current_grid[j + i * hello.piece_grid_side] != 0 &&
                grid[(future_pos_x + j + pos_y * grid_width + (i * 12))] != 0)
            {

                return true;
            }
        }
    }
    return false;
}

void Level::piece_movement()
{
    if (hello.rotation_input != 0)
    {
        hello.piece_rotation();
    }

    if (hello.input.y == 1)
    {
        gravity_time = 3;
    }
    else if (hello.input.y == 0)
    {
        gravity_time = 60;
    }

    if (!piece_collision((int)(hello.pos.x + hello.input.x), (int)(hello.pos.y)))
    {
        hello.pos.x += hello.input.x;
    }

    if (gravity_counter >= gravity_time)
    {
        falling = true;
        if (!piece_collision((int)hello.pos.x, (int)hello.pos.y))
        {
            hello.pos.y++;
            gravity_counter = 0;
        }
        else
        {
            piece_lock();
        }
        falling = false;
    }

    gravity_counter++;
}

void Level::piece_lock()
{
    for (int i = 0; i < hello.piece_grid_side; i++)
    {
        for (int j = 0; j < hello.piece_grid_side; j++)
        {
            if (hello.current_grid[j + i * hello.piece_grid_side] != 0)
            {
                grid[((int)hello.pos.x + j + (int)hello.pos.y * grid_width + (i * 12))] = hello.current_grid[j + i * hello.piece_grid_side];
            }
        }
    }

    hello.change_piece(hello.next_grid, hello.next_piece); // to next piece
    hello.random_piece();
    hello.pos = { 2,0 };
}

void Level::update()
{
    hello.update();
    piece_movement();
}

void Level::render()
{
    for (int i = 0; i < grid_height; i++)
    {
        for (int j = 0; j < grid_width; j++)
        {
            switch (grid[j + i * grid_width])
            {
            case(0):    cell_color = WHITE;
                break;
            case(1):    cell_color = GRAY;
                break;
            case(2):    cell_color = BLUE;
                break;
            case(3):    cell_color = RED;
                break;
            case(4):    cell_color = YELLOW;
                break;
            case(5):    cell_color = GREEN;
                break;
            case(6):    cell_color = PURPLE;
                break;
            case(7):    cell_color = DARKBLUE;
                break;
            case(8):    cell_color = ORANGE;
                break;
            }

                DrawRectangle(j * cell_pixel_side + (int)level_pos.x, i * cell_pixel_side + (int)level_pos.y, cell_pixel_side, cell_pixel_side, cell_color);
        }
    }

    hello.render(level_pos);
}