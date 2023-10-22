#include "collision.h"

void Collision_Test::update()
{
	if (sqrt((GetMouseX() - obj1_pos.x) * (GetMouseX() - obj1_pos.x) + (GetMouseY() - obj1_pos.y) * (GetMouseY() - obj1_pos.y)) <= circle_radius && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		circle_color = RED;
		obj1_pos.x = (float)GetMouseX();
		obj1_pos.y =(float)GetMouseY();
	}
}

void Collision_Test::render()
{
	DrawCircle((int)obj1_pos.x, (int)obj1_pos.y, (float)circle_radius, circle_color);
	DrawRectangle((int)obj2_pos.x, (int)obj2_pos.y, aabb_size, aabb_size, WHITE);

	DrawText("Collision screen", 100, 100, 60, WHITE);
}