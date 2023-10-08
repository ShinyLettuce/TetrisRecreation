#include "level.h"

void Level::init()
{
    hello.change_piece(hello.S);
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

//void Level::piece_rotation()
//{
//    //Move back to tetromino controller
//
//    if (hello.rotation_input != 0)
//    {
//        //hello.rotation_index++;
//        for (int y = -1; y < 3; y++)
//        {
//            for (int x = -1; x < 3; x++)
//            {
//                switch (hello.rotation_index % 4)
//                {
//                case(0):
//                    //90 degrees
//                    hello.current_grid[(x + 1) + (y + 1) * 4] = hello.shapes.grid_S[(-y + 1) + (x + 1) * 4];
//                    break;
//                case(1):
//                    //180 degrees
//                    hello.current_grid[(x + 1) + (y + 1) * 4] = hello.shapes.grid_S[(-x + 1) + (-y + 1) * 4];
//                    break;
//                case(2):
//                    //270 degrees
//                    hello.current_grid[(x + 1) + (y + 1) * 4] = hello.shapes.grid_S[(y + 1) + (-x + 1) * 4];
//                    break;
//                case(3):
//                    //360 degrees
//                    hello.current_grid[(x + 1) + (y + 1) * 4] = hello.shapes.grid_S[(x + 1) + (y + 1) * 4];
//                    break;
//                    
//                }
//            }
//        }
//        hello.rotation_index++;
//    }
//}

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

    hello.change_piece(hello.I); // to next piece
    hello.pos = { 2,0 };
}

void Level::update()
{
    hello.update();
    piece_movement();
    //piece_rotation();
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