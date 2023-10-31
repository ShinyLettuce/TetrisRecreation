#include "collision.h"

bool Collision_Test::point_circle_collision(int point_x, int point_y, Vector2 circle1_pos, int circle1_radius)
{
	if (sqrt((point_x - circle1_pos.x) * (point_x - circle1_pos.x) + (point_y - circle1_pos.y) * (point_y - circle1_pos.y)) <= circle1_radius)
	{
		return true;
	}
	return false;
}

bool Collision_Test::point_aabb_collision(int point_x, int point_y, Vector2 aabb_pos, Vector2 aabb_w_h)
{
	if (point_x <= aabb_pos.x + aabb_w_h.x &&
		point_x >= aabb_pos.x &&
		point_y <= aabb_pos.y + aabb_w_h.y &&
		point_y >= aabb_pos.y)
	{
		return true;
	}
	return false;
}

void Collision_Test::clamp_aabb_to_mouse(Vector2& obj_position, Vector2 aabb_w_h, bool& selection)
{
	selection = true;
	obj_position.x = (float)GetMouseX() - aabb_w_h.x / 2;
	obj_position.y = (float)GetMouseY() - aabb_w_h.y / 2;
}

void Collision_Test::clamp_circle_to_mouse(Vector2& obj_position, bool& selection)
{
	selection = true;
	obj_position.x = (float)GetMouseX();
	obj_position.y = (float)GetMouseY();
}

bool Collision_Test::aabb_circle_collision(Vector2 aabb_pos, Vector2 aabb_w_h, Vector2 circle_pos, int circle_radius) // TRIED AND TRUE
{
	Vector2 closest_pos = { 0,0 };
	
	if (circle_pos.x < aabb_pos.x)
	{
		closest_pos.x = aabb_pos.x;
	}
	else if (circle_pos.x > aabb_pos.x + aabb_w_h.x)
	{
		closest_pos.x = aabb_pos.x + aabb_w_h.x;
	}
	else
	{
		closest_pos.x = circle_pos.x;
	}
	if (circle_pos.y < aabb_pos.y)
	{
		closest_pos.y = aabb_pos.y;
	}
	else if (circle_pos.y > aabb_pos.y + aabb_w_h.y)
	{
		closest_pos.y = aabb_pos.y + aabb_w_h.y;
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

bool Collision_Test::aabb_aabb_collision(Vector2 aabb1_pos, Vector2 aabb1_w_h, Vector2 aabb2_pos, Vector2 aabb2_w_h)
{
	if (aabb1_pos.x <= aabb2_pos.x + aabb2_w_h.x &&
		aabb1_pos.x + aabb1_w_h.x >= aabb2_pos.x &&
		aabb1_pos.y <= aabb2_pos.y + aabb2_w_h.y &&
		aabb1_pos.y + aabb1_w_h.y >= aabb2_pos.y)
	{
		return true;
	}
	return false;
}

bool Collision_Test::circle_line_collision(Vector2 line_position1, Vector2 line_position2, Vector2 circle_pos, int circle_radius)
{
	float t = (Vector2DotProduct(Vector2Subtract(circle_pos, line_position1), Vector2Subtract(line_position2, line_position1)) / (Vector2DotProduct(Vector2Subtract(line_position2, line_position1), Vector2Subtract(line_position2, line_position1))));
	if (t > 1)
	{
		t = 1;
	}
	if (t < 0)
	{
		t = 0;
	}
	Vector2 closest_point = Vector2Add(line_position1,Vector2Scale(Vector2Subtract(line_position2, line_position1),t));
	
	return point_circle_collision((int)closest_point.x, (int)closest_point.y,circle_pos,circle_radius);
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
		obj1_pos = { 200,300 };
		line_pos1 = { 500,100 };
		line_pos2 = { 500,400 };
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
		if (point_aabb_collision(GetMouseX(), GetMouseY(), obj2_pos, aabbox_width_height) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj1_selected)
		{
			clamp_aabb_to_mouse(obj2_pos, aabbox_width_height, obj2_selected);
		}
		if (aabb_circle_collision(obj2_pos, aabbox_width_height, obj1_pos, circle_rad))
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
		if (point_circle_collision(GetMouseX(), GetMouseY(), line_pos1, 10) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj1_selected)
		{
			clamp_circle_to_mouse(line_pos1, obj2_selected);
		}
		if (point_circle_collision(GetMouseX(), GetMouseY(), line_pos2, 10) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj1_selected)
		{
			clamp_circle_to_mouse(line_pos2, obj2_selected);
		}
		if (point_circle_collision(GetMouseX(), GetMouseY(), obj1_pos, circle_rad) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj2_selected)
		{
			clamp_circle_to_mouse(obj1_pos, obj1_selected);
		}
		if(circle_line_collision(line_pos1, line_pos2, obj1_pos, circle_rad))
		{
			obj1_color = GREEN;
			obj2_color = GREEN;
		}
		break;
	case(Collision_Type::AABB_V_AABB):
		if (point_aabb_collision(GetMouseX(), GetMouseY(), obj1_pos, aabbox_width_height) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj2_selected)
		{
			clamp_aabb_to_mouse(obj1_pos, aabbox_width_height, obj1_selected);
		}
		if (point_aabb_collision(GetMouseX(), GetMouseY(), obj2_pos, aabbox_width_height) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !obj1_selected)
		{
			clamp_aabb_to_mouse(obj2_pos, aabbox_width_height, obj2_selected);
		}
		if (aabb_aabb_collision(obj2_pos, aabbox_width_height, obj1_pos, aabbox_width_height))
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
		DrawCircleV(obj1_pos, (float)circle_rad, obj1_color);
		DrawRectangleV(obj2_pos, aabbox_width_height, obj2_color);
		break;
	case(Collision_Type::CIRCLE_V_CIRCLE):
		DrawCircleV(obj1_pos, (float)circle_rad, obj1_color);
		DrawCircleV(obj2_pos, (float)circle_rad, obj2_color);
		break;
	case(Collision_Type::CIRCLE_V_LINE):
		DrawCircleV(obj1_pos, (float)circle_rad, obj1_color);
		DrawLineV(line_pos1, line_pos2, obj2_color);
		DrawCircleV(line_pos1, 10, obj2_color);
		DrawCircleV(line_pos2, 10, obj2_color);
		break;
	case(Collision_Type::AABB_V_AABB):
		DrawRectangleV(obj1_pos, aabbox_width_height, obj1_color);
		DrawRectangleV(obj2_pos, aabbox_width_height, obj2_color);
		break;
	}

	DrawText("Collision screen", 100, 100, 60, WHITE);
}