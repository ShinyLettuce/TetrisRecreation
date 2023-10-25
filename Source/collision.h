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
	Color aabbox_color = WHITE;

	bool aabb_circle_collision(Vector2 aabb_pos, int aabb_width, int aabb_height, Vector2 circle_pos, int circle_radius);
	bool circle_circle_collision(Vector2 circle1_pos, int circle1_radius, Vector2 circle2_pos, int circle2_radius);
	bool aabb_aabb_collision(Vector2 aabb1_pos, int aabb1_width, int aabb1_height, Vector2 aabb2_pos, int aabb2_width, int aabb2_height);

	void update();
	void render();
};