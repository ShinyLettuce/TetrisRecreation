#pragma once
#include "raylib.h"
#include <cmath>

struct Collision_Test
{
	Vector2 obj1_pos = {200,300};
	Vector2 obj2_pos = { 500,200 };
	int circle_radius = 100;
	int aabb_size = 200;
	Color circle_color = WHITE;

	void update();
	void render();
};