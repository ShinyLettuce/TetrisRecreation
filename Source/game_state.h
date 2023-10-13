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

	Level level;
	std::stack<GAME_STATE> game_state;	

	void game_screen();
	void menu_screen();
	void high_score_screen();
	void collision_screen();

	void update();
};