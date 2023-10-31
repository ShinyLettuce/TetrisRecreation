#pragma once
#include "raylib.h"
#include <cmath>
#include <numeric>
#include "raymath.h"
#include <iostream>

struct Collision_Test
{
	enum class Collision_Type
	{
		NO_TYPE,
		CIRCLE_V_CIRCLE,
		CIRCLE_V_AABB,
		CIRCLE_V_LINE,
		AABB_V_AABB
	};

	Collision_Type collision_type = Collision_Type::NO_TYPE;

	Vector2 obj1_pos = {200,300};
	Vector2 obj2_pos = { 500,200 };
	Vector2 line_pos1 = {500,100};
	Vector2 line_pos2 = {500,400};
	Vector2 aabbox_width_height = {200,200};
	int circle_rad = 100;
	Color obj1_color = WHITE;
	Color obj2_color = WHITE;

	bool obj1_selected = false;
	bool obj2_selected = false;

	bool point_circle_collision(int point_x, int point_y, Vector2 circle1_pos, int circle1_radius);
	bool point_aabb_collision(int point_x, int point_y, Vector2 aabb_pos, Vector2 aabb_w_h);
	void clamp_aabb_to_mouse(Vector2& obj_position, Vector2 aabb_w_h, bool& selection);
	void clamp_circle_to_mouse(Vector2& obj_position, bool& selection);

	bool aabb_circle_collision(Vector2 aabb_pos, Vector2 aabb_w_h, Vector2 circle_pos, int circle_radius);
	bool circle_circle_collision(Vector2 circle1_pos, int circle1_radius, Vector2 circle2_pos, int circle2_radius);
	bool aabb_aabb_collision(Vector2 aabb1_pos, Vector2 aabb1_w_h, Vector2 aabb2_pos, Vector2 aabb2_w_h);
	bool circle_line_collision(Vector2 line_pos1, Vector2 line_pos2, Vector2 circle_pos, int circle_radius);

	void update();
	void render();
};