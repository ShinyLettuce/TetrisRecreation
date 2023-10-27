#pragma once
#include <stack>
#include "file.h"
#include "level.h"
#include "media.h"
#include "main_menu.h"
#include "collision.h"

struct Game_State
{
	enum class GAME_STATE
	{
		MAIN_MENU,
		GAME_SCREEN,
		COLLISION_SCREEN,
		HIGH_SCORE_SCREEN,
	};

	std::string high_score_file;

	Level level;
	Main_Menu menu;
	Collision_Test collision;
	File_Manager file;
	std::stack<GAME_STATE> game_state;	

	void game_screen();
	void menu_screen();
	void high_score_screen();
	void collision_screen();

	void update();
};