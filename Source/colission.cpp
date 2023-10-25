#include "collision.h"

bool Collision_Test::aabb_circle_collision(Vector2 aabb_pos, int aabb_width, int aabb_height, Vector2 circle_pos, int circle_radius) // TRIED AND TRUE
{
	Vector2 closest_pos = { 0,0 };
	
	if (circle_pos.x < aabb_pos.x)
	{
		closest_pos.x = aabb_pos.x;
	}
	else if (circle_pos.x > aabb_pos.x + aabb_width)
	{
		closest_pos.x = aabb_pos.x + aabb_width;
	}
	else
	{
		closest_pos.x = circle_pos.x;
	}
	if (circle_pos.y < aabb_pos.y)
	{
		closest_pos.y = aabb_pos.y;
	}
	else if (circle_pos.y > aabb_pos.y + aabb_height)
	{
		closest_pos.y = aabb_pos.y + aabb_height;
	}
	else
	{
		closest_pos.y = circle_pos.y;
	}
	if (sqrt((circle_pos.x - closest_pos.x) * (circle_pos.x - closest_pos.x) + (circle_pos.y - closest_pos.y) * (circle_pos.y - closest_pos.y)) <= circle_radius)
	{
		return true;
	}
	return false;
}

bool Collision_Test::circle_circle_collision(Vector2 circle1_pos, int circle1_radius, Vector2 circle2_pos, int circle2_radius)
{
	if (sqrt((circle1_pos.x - circle2_pos.x) * (circle1_pos.x - circle2_pos.x) + (circle1_pos.y - circle2_pos.y) * (circle1_pos.y - circle2_pos.y)) <= (circle1_radius + circle2_radius))
	{
		return true;
	}
	return false;
}

bool Collision_Test::aabb_aabb_collision(Vector2 aabb1_pos, int aabb1_width, int aabb1_height, Vector2 aabb2_pos, int aabb2_width, int aabb2_height)
{
	if (aabb1_pos.x >= aabb2_pos.x + aabb2_width &&
		aabb1_pos.x + aabb1_width <= aabb2_pos.x &&
		aabb1_pos.y >= aabb2_pos.y + aabb2_height &&
		aabb1_pos.y + aabb2_height >= aabb2_pos.y)
	{
		return true;
	}
	return false;
}

void Collision_Test::update()
{
	if (sqrt((GetMouseX() - obj1_pos.x) * (GetMouseX() - obj1_pos.x) + (GetMouseY() - obj1_pos.y) * (GetMouseY() - obj1_pos.y)) <= circle_rad && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		circle_color = RED;
		obj1_pos.x = (float)GetMouseX();
		obj1_pos.y =(float)GetMouseY();
	}

	if (aabb_circle_collision(obj2_pos, aabbox_width, aabbox_height, obj1_pos, circle_rad))
	{
		circle_color = GREEN;
	}

}

void Collision_Test::render()
{
	DrawCircle((int)obj1_pos.x, (int)obj1_pos.y, (float)circle_rad, circle_color);
	DrawRectangle((int)obj2_pos.x, (int)obj2_pos.y, aabbox_width, aabbox_height, WHITE);

	DrawText("Collision screen", 100, 100, 60, WHITE);
}