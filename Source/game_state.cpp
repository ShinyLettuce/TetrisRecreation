#include "game_state.h"

void Game_State::game_screen()
{
	level.update();
	menu.update();
	menu.render();
	level.render();

	if (level.lock_out)
	{
		game_state.push(GAME_STATE::HIGH_SCORE_SCREEN);
		high_score.init();
	}
}

void Game_State::menu_screen()
{
	menu.update();
	menu.render();

	if (game_state.top() == GAME_STATE::MAIN_MENU)
	{
		DrawText("press x to start", 490, 700, 36, WHITE);
		DrawText("press c to test", 490, 750, 36, WHITE);
	}

	if (IsKeyDown(KEY_X))
	{
		level.init();
		game_state.push(Game_State::GAME_STATE::GAME_SCREEN);
	}
	if (IsKeyDown(KEY_C))
	{
		game_state.push(Game_State::GAME_STATE::COLLISION_SCREEN);
	}
}

void Game_State::high_score_screen()
{
	if (!high_score.score_saved)
	{
		high_score.enter_name_update(level.score);
	}

	high_score.render(level.score);

	if (high_score.score_saved && IsKeyPressed(KEY_T))
	{
		game_state.pop();
		game_state.pop();
	}
}

void Game_State::collision_screen()
{
	collision.update();
	collision.render();

	if (IsKeyPressed(KEY_T))
	{
		game_state.pop();
	}
}

void Game_State::update()
{
	switch (game_state.top())
	{
	case GAME_STATE::MAIN_MENU :
		menu_screen();
		break;
	case GAME_STATE::GAME_SCREEN:
		game_screen();
		break;
	case GAME_STATE::HIGH_SCORE_SCREEN:
		high_score_screen();
		break;
	case GAME_STATE::COLLISION_SCREEN:
		collision_screen();
		break;
	}
}