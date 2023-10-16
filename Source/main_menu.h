#pragma once
#include "raylib.h"
#include "media.h"

struct Main_Menu {

	Vector2 hill_pos = { -190, 50 };
	Vector2 hill_pos2 = { -1190, 50 };
	Vector2 cloud_pos = { -190, 0 };
	Vector2 cloud_pos2 = { -1190, 0 };
	Vector2 car_pos = { 0,20 };
	Vector2 pole_pos = { -100, 0 };
	int car_counter = 0;
	int cloud_counter = 0;
	int hill_counter = 0;
	int pole_counter = 0;

	void render();
};