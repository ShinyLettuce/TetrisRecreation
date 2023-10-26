#include "collision.h"

bool Collision_Test::point_circle_collision(int point_x, int point_y, Vector2 circle1_pos, int circle1_radius)
{
	if (sqrt((point_x - circle1_pos.x) * (point_x - circle1_pos.x) + (point_y - circle1_pos.y) * (point_y - circle1_pos.y)) <= circle1_radius)
	{
		return true;
	}
	return false;
}

bool Collision_Test::point_aabb_collision(int point_x, int point_y, Vector2 aabb_pos, int aabb_width, int aabb_height)
{
	if (point_x <= aabb_pos.x + aabb_width &&
		point_x >= aabb_pos.x &&
		point_y <= aabb_pos.y + aabb_height &&
		point_y >= aabb_pos.y)
	{
		return true;
	}
	return false;
}

void Collision_Test::clamp_aabb_to_mouse(Vector2& obj_position, int aabb_width, int aabb_height, bool& selection)
{
	selection = true;
	obj_position.x = (float)GetMouseX() - aabb_width / 2;
	obj_position.y = (float)GetMouseY() - aabb_height / 2;
}

void Collision_Test::clamp_circle_to_mouse(Vector2& obj_position, bool& selection)
{
	selection = true;
	obj_position.x = (float)GetMouseX();
	obj_position.y = (float)GetMouseY();
}

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
	if (aabb1_pos.x <= aabb2_pos.x + aabb2_width &&
		aabb1_pos.x + aabb1_width >= aabb2_pos.x &&
		aabb1_pos.y <= aabb2_pos.y + aabb2_height &&
		aabb1_pos.y + aabb1_height >= aabb2_pos.y)
	{
		return true;
	}
	return false;
}

void Collision_Test::update()
{
	if (IsKeyPressed(KEY_ONE))
	{
		obj1_pos = { 200,300 };
		obj2_pos = { 500,200 };
		collision_type = Collision_Type::CIRCLE_V_AABB;
	}
	if (IsKeyPressed(KEY_TWO))
	{
		obj1_pos = { 200,300 };
		obj2_pos = { 500,300 };
		collision_type = Collision_Type::CIRCLE_V_CIRCLE;
	}
	if (IsKeyPressed(KEY_THREE))
	{
		collision_type = Collision_Type::CIRCLE_V_LINE;
	}
	if (IsKeyPressed(KEY_FOUR))
	{
		obj1_pos = { 200,200 };
		obj2_pos = { 500,200 };
		collision_type = Collision_Type::AABB_V_AABB;
	}

	obj1_color = RED;
	obj2_color = RED;

	if (IsMouseButtonUp(MOUSE_LEFT_BUTTON))
	{
		obj1_selected = false;
		obj2_selected = false;
	}

	switch (collision_type)
	{
	case(Collision_Type::CIRCLE_V_AABB):
		if (point_circle_collision(GetMouseX(), GetMouseY(), obj1_pos, circle_rad) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj2_selected)
		{
			clamp_circle_to_mouse(obj1_pos, obj1_selected);
		}
		if (point_aabb_collision(GetMouseX(), GetMouseY(), obj2_pos, aabbox_width, aabbox_height) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj1_selected)
		{
			clamp_aabb_to_mouse(obj2_pos, aabbox_width, aabbox_height, obj2_selected);
		}
		if (aabb_circle_collision(obj2_pos, aabbox_width, aabbox_height, obj1_pos, circle_rad))
		{
			obj1_color = GREEN;
			obj2_color = GREEN;
		}
		break;
	case(Collision_Type::CIRCLE_V_CIRCLE):
		if (point_circle_collision(GetMouseX(), GetMouseY(), obj1_pos, circle_rad) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj2_selected)
		{
			clamp_circle_to_mouse(obj1_pos, obj1_selected);
		}
		if (point_circle_collision(GetMouseX(), GetMouseY(), obj2_pos, circle_rad) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj1_selected)
		{
			clamp_circle_to_mouse(obj2_pos, obj2_selected);
		}
		if (circle_circle_collision(obj2_pos, circle_rad, obj1_pos, circle_rad))
		{
			obj1_color = GREEN;
			obj2_color = GREEN;
		}
		break;
	case(Collision_Type::CIRCLE_V_LINE):
		break;
	case(Collision_Type::AABB_V_AABB):
		if (point_aabb_collision(GetMouseX(), GetMouseY(), obj1_pos, aabbox_width, aabbox_height) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj2_selected)
		{
			clamp_aabb_to_mouse(obj1_pos, aabbox_width, aabbox_height, obj1_selected);
		}
		if (point_aabb_collision(GetMouseX(), GetMouseY(), obj2_pos, aabbox_width, aabbox_height) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj1_selected)
		{
			clamp_aabb_to_mouse(obj2_pos, aabbox_width, aabbox_height, obj2_selected);
		}
		if (aabb_aabb_collision(obj2_pos, aabbox_width, aabbox_height, obj1_pos, aabbox_width, aabbox_height))
		{
			obj1_color = GREEN;
			obj2_color = GREEN;
		}
		break;
	}
}

void Collision_Test::render()
{
	switch (collision_type)
	{
	case(Collision_Type::CIRCLE_V_AABB):
		DrawCircle((int)obj1_pos.x, (int)obj1_pos.y, (float)circle_rad, obj1_color);
		DrawRectangle((int)obj2_pos.x, (int)obj2_pos.y, aabbox_width, aabbox_height, obj2_color);
		break;
	case(Collision_Type::CIRCLE_V_CIRCLE):
		DrawCircle((int)obj1_pos.x, (int)obj1_pos.y, (float)circle_rad, obj1_color);
		DrawCircle((int)obj2_pos.x, (int)obj2_pos.y, (float)circle_rad, obj2_color);
		break;
	case(Collision_Type::CIRCLE_V_LINE):
		break;
	case(Collision_Type::AABB_V_AABB):
		DrawRectangle((int)obj1_pos.x, (int)obj1_pos.y, aabbox_width, aabbox_height, obj1_color);
		DrawRectangle((int)obj2_pos.x, (int)obj2_pos.y, aabbox_width, aabbox_height, obj2_color);
		break;
	}

	DrawText("Collision screen", 100, 100, 60, WHITE);
}