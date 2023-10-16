#pragma once
#include "raylib.h"
#include "tetromino_controller.h"

struct Level {
    Vector2 level_pos{ 0,-50 };
    Tetromino_controller player;

    int grid_width = 12;
    int grid_height = 20;
    int cell_pixel_side = 50;
    int line_scan_count = 0;
    Color cell_color;
    Color dark_transparent = { 50, 50, 60, 220 };

    int x_movement_timer = 0;
    int gravity_progression[21] = { 53, 49, 45, 41, 37, 33, 28, 22, 17, 11, 10, 9, 8, 7, 6, 6, 5, 5, 4, 4, 3 };
    int gravity_time = gravity_progression[0];
    int gravity_counter = 0;
    bool falling = false;

    int score = 0;
    int level = 0;
    int lines_cleared_in_a_frame = 0;
    int lines_cleared_total = 0;
    bool lock_out = false;


    int grid[240] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

    void init();
    bool piece_collision(int future_pos_x, int pos_y); // probably change the passed variable names
    void piece_movement();
    void piece_lock();
    void line_scan();
    void remove_line(int line);
    void add_score(int number_of_lines_cleared);
    void clear_grid();

    void update();
    void render();
};