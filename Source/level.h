#pragma once
#include "raylib.h"
#include "tetromino_controller.h"
#include "media.h"

struct Level {
    Vector2 level_pos{ 0,-50 };
    Tetromino_controller player;

    const int grid_width = 12;
    const int grid_height = 20;
    const int cell_pixel_side = 50;
    int line_scan_count = 0;
    Color cell_color;
    const Color dark_transparent = { 50, 50, 60, 220 };

    int x_movement_timer = 0;
    const int gravity_progression[21] = { 53, 49, 45, 41, 37, 33, 28, 22, 17, 11, 10, 9, 8, 7, 6, 6, 5, 5, 4, 4, 3 };
    const int soft_drop_speed = 3;
    int gravity_time = gravity_progression[0];
    int gravity_counter = 0;
    bool falling = false;

    const int line_based_score[4] = { 40,100,300,1200 };
    int score = 0;
    int level = 0;
    int lines_cleared_in_a_frame = 0;
    int lines_cleared_total = 0;
    bool lock_out = false;

    bool anim_should_play = false;
    int anim_counter = 0;
    float texture_x = 0;


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
    bool piece_collision(int future_pos_x, int pos_y);
    void piece_movement();
    void piece_lock();
    void line_scan();
    void remove_line(int line);
    inline void add_score(int number_of_lines_cleared);
    void clear_grid();

    void update();
    void render();
};