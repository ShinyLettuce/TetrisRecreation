#pragma once
#include <stack>
#include "level.h"

struct Game_State
{
	enum class GAME_STATE
	{
		MAIN_MENU,
		GAME_SCREEN,
		COLLISION_SCREEN,
		HIGH_SCORE_SCREEN,
	};


	Vector2 hill_pos = { -190, 50 };
	Vector2 hill_pos2 = { -1190, 50 };
	Vector2 cloud_pos = {-190, 0};
	Vector2 cloud_pos2 = {-1190, 0};
	Vector2 car_pos = { 0,20 };
	Vector2 pole_pos = { -100, 0 };
	int car_counter = 0;
	int cloud_counter = 0;
	int hill_counter = 0;
	int pole_counter = 0;

	Texture2D hills;
	Texture2D hills2;
	Texture2D sky;
	Texture2D car;
	Texture2D clouds;
	Texture2D clouds2;
	Texture2D lake;
	Texture2D pole;
	Texture2D title;

	Level level;
	std::stack<GAME_STATE> game_state;	

	void game_screen();
	void menu_screen();
	void menu_render();
	void high_score_screen();
	void collision_screen();

	void update();
};