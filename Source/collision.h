#pragma once
#include "raylib.h"
#include <cmath>

struct Collision_Test
{
	Vector2 obj1_pos = {200,300};
	Vector2 obj2_pos = { 500,200 };
	int circle_rad = 100;
	int aabbox_height = 200;
	int aabbox_width = 200;
	Color circle_color = WHITE;

	bool aabb_circle_collision(Vector2 aabb_pos, int aabb_width, int aabb_height, Vector2 circle_pos, int circle_radius);

	void update();
	void render();
};