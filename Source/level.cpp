#include "level.h"

void Level::init()
{

}

bool Level::piece_collision(int future_pos_x, int pos_y, bool falling)
{
    if (falling)
    {
        pos_y++;
    }

    for (int i = 0; i < hello.piece_grid_side; i++)
    {
        for (int j = 0; j < hello.piece_grid_side; j++)
        {
            if (hello.grid_S[j + i * hello.piece_grid_side] != 0 &&
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

    if (hello.input.y == 1)
    {
        gravity_time = 3;
    }
    else if (hello.input.y == 0)
    {
        gravity_time = 60;
        falling = true;
    }

    if (!piece_collision((int)(hello.pos.x + hello.input.x), (int)(hello.pos.y + hello.input.y), falling))
    {
        hello.pos.x += hello.input.x;

        if (gravity_counter >= gravity_time)
        {
            hello.pos.y++;
            gravity_counter = 0;
        }

        falling = false;
    }

    gravity_counter++;
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
            if (grid[j + i * grid_width] == 0)
            {
                DrawRectangle(j * cell_pixel_side, i * cell_pixel_side, cell_pixel_side, cell_pixel_side, WHITE);
            }
            if (grid[j + i * grid_width] == 1)
            {
                DrawRectangle(j * cell_pixel_side, i * cell_pixel_side, cell_pixel_side, cell_pixel_side, GRAY);
            }
        }
    }

    hello.render();
}