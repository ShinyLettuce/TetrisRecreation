#include "level.h"

void Level::init()
{
    player.random_piece();
    player.change_piece(player.next_grid, player.next_piece);
    player.random_piece();

}

bool Level::piece_collision(int future_pos_x, int pos_y)
{
    if (falling)
    {
        pos_y++;
    }

    for (int i = 0; i < player.piece_grid_side; i++)
    {
        for (int j = 0; j < player.piece_grid_side; j++)
        {
            if (player.current_grid[j + i * player.piece_grid_side] != 0 &&
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
    if (player.rotation_input != 0)
    {
        player.piece_rotation();
        if (piece_collision((int)(player.pos.x), (int)(player.pos.y)))
        {
            player.rotation_input = -player.rotation_input;
            player.piece_rotation();
        }
    }

    if (player.input.y == 1)
    {
        gravity_time = 3;
    }
    else if (player.input.y == 0)
    {
        gravity_time = gravity;
    }

    if (!piece_collision((int)(player.pos.x + player.input.x), (int)(player.pos.y)) &&
        player.input.x != 0)
    {
        if (x_movement_timer == 0)
        {
            player.pos.x += player.input.x;
        }
        else if (x_movement_timer >= player.x_movement_speed)
        {
            player.pos.x += player.input.x;
            x_movement_timer = 14;
        }
        x_movement_timer++;
    }
    else
    {
        x_movement_timer = 0;
    }

    if (gravity_counter >= gravity_time)
    {
        falling = true;
        if (!piece_collision((int)player.pos.x, (int)player.pos.y))
        {
            player.pos.y++;
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
    for (int i = 0; i < player.piece_grid_side; i++)
    {
        for (int j = 0; j < player.piece_grid_side; j++)
        {
            if (player.current_grid[j + i * player.piece_grid_side] != 0)
            {
                grid[((int)player.pos.x + j + (int)player.pos.y * grid_width + (i * 12))] = player.current_grid[j + i * player.piece_grid_side];
            }
        }
    }

    line_scan();

    player.change_piece(player.next_grid, player.next_piece);
    player.random_piece();
    player.pos = { 4,1 };
    player.rotation_index = 0;
    gravity_counter = 0;
}

void Level::line_scan()
{
    for (int i = 0; i < grid_height; i++)
    {
        for (int j = 0; j < grid_width; j++)
        {
            if (grid[j + i * grid_width] != 0 && grid[j + i * grid_width] != 1)
            {
                line_scan_count++;
            }
            if (line_scan_count == 10)
            {
                remove_line(i);
                lines_cleared_in_a_frame++;
                line_scan_count = 0;
            }
        }
        line_scan_count = 0;
    }
    if (lines_cleared_in_a_frame > 0)
    {
        add_score(lines_cleared_in_a_frame);
        lines_cleared_in_a_frame = 0;
    }
}

void Level::remove_line(int line)
{
    for (int i = 1; i < grid_width - 1; i++)
    {
        grid[i + line * grid_width] = 0;
    }

    for (int i = line; i > 0; i--)
    {
        for (int j = 1; j < grid_width -1; j++)
        {
            grid[j + i * grid_width] = grid[j + (i - 1) * grid_width];
        }
    }
}

void Level::add_score(int number_of_lines_cleared)
{
    switch (number_of_lines_cleared)
    {
    case(1):
        score += 40;
        break;
    case(2):
        score += 100;
        break;
    case(3):
        score += 300;
        break;
    case(4):
        score += 1200;
        break;
    default:
        break;
    }
}

void Level::update()
{
    player.update();
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

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (player.next_grid[j + i * 4] != 0)
            {
                DrawRectangle(j * cell_pixel_side + 610, i * cell_pixel_side + 600, cell_pixel_side, cell_pixel_side, WHITE);
            }
        }
    }

    DrawText("SCORE", 640, 60, 38, WHITE);
    DrawText(TextFormat("%05i", score), 655, 100, 38, WHITE);
    DrawText("LEVEL", 640, 300, 38, WHITE);
    DrawText("LINES", 640, 400, 38, WHITE);

    player.render(level_pos);
}