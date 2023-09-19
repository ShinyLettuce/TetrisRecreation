#include "raylib.h"
#include <iostream>

struct Tetronimo_controller
{
    Vector2 pos = { 0,0 };
    Vector2 input = { 0,0 };
    int rotation_index = 0;

    enum PIECES
    {
        L,
        I,
        T,
        J,
        S,
        Z,
        O
    };

    int current_piece = NULL;

    int current_grid[16] = { 0,0,0,0,
                             0,0,0,0,
                             0,0,0,0,
                             0,0,0,0, };

    int grid_L[16] = { 0,0,0,0,
                       1,1,1,0,
                       1,0,0,0,
                       0,0,0,0, };

    int grid_I[16] = { 0,0,0,0,
                       1,1,1,1,
                       0,0,0,0,
                       0,0,0,0, };

    int grid_T[16] = { 0,0,0,0,
                       1,1,1,0,
                       0,1,0,0,
                       0,0,0,0, };

    int grid_J[16] = { 0,0,0,0,
                       1,1,1,0,
                       0,0,1,0,
                       0,0,0,0, };

    int grid_S[16] = { 0,0,0,0,
                       0,1,1,0,
                       1,1,0,0,
                       0,0,0,0, };

    int grid_Z[16] = { 0,0,0,0,
                       1,1,0,0,
                       0,1,1,0,
                       0,0,0,0, };

    int grid_O[16] = { 0,0,0,0,
                       0,1,1,0,
                       0,1,1,0,
                       0,0,0,0, };

    void update();
    void render();

    void rotate();
};

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
    //if (IsKeyDown(KEY_C))
    //{
    //    rotate();
    //}
}

void Tetronimo_controller::render()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(grid_S[j + i*4] == 1)
            DrawRectangle(((int)pos.x * 50) + (j * 50), ((int)pos.y * 50) + (i * 50), 50, 50, RED);
        }
    }

}

void Tetronimo_controller::rotate()
{
    /*
    for (int y = -1; y < 3; y++)
    {
        for (int x = -1; x < 3; x++)
        {
            switch (rotation_index)
            {
            case(1):
                //90 degrees
                current_grid[(x + 1) + (y + 1) * 4] = piece_grid[(-y + 1) + (x + 1) * 4];
                break;
            case(2):
                //180 degrees
                current_grid[(x + 1) + (y + 1) * 4] = piece_grid[(-x + 1) + (-y + 1) * 4];
                break;
            case(3):
                //270 degrees
                current_grid[(x + 1) + (y + 1) * 4] = piece_grid[(y + 1) + (-x + 1) * 4];
                break;

            }
        }
    }
    */
}

struct Level {
    Tetronimo_controller hello;

    int grid_width = 10;
    int grid_height = 18;
    int cell_pixel_side = 50;

    int gravity_counter = 0;
    int gravity_time = 60;


    int grid[180] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

    void init();

    void piece_movement();

    void update();
    void render();
};

void Level::init() 
{

}

void Level::piece_movement()
{

    if (hello.input.y == 1)
    {
        gravity_time = 3;
    }
    else if(hello.input.y == 0)
    {
        gravity_time = 60;
    }

    hello.pos.x += hello.input.x;


    if (gravity_counter >= gravity_time)
    {
        hello.pos.y++;
        gravity_counter = 0;
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
            DrawRectangle(j*cell_pixel_side, i*cell_pixel_side, cell_pixel_side, cell_pixel_side, WHITE);
        }
    }

    hello.render();
}

int main(void)
{    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 810;
    const int screenHeight = 900;
    Level level;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);              

    //--------------------------------------------------------------------------------------

    InitAudioDevice();

    auto sound = LoadSound("./hitHurt.ogg");


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        level.update();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        level.render();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseAudioDevice();
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}