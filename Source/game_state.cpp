#include "game_state.h"

void Game_State::game_screen()
{
	level.update();
	level.render();
}

void Game_State::menu_screen()
{
	level.render();

	DrawText("TETRIS", 95, 300, 96, BLACK);
	DrawText("Press X to start", 90, 500, 48, BLACK);

	if (IsKeyDown(KEY_X))
	{
		level.init();
		game_state.push(Game_State::GAME_STATE::GAME_SCREEN);
	}
}

void Game_State::high_score_screen()
{

}

void Game_State::collision_screen()
{

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
		break;
	case GAME_STATE::COLLISION_SCREEN:
		break;
	}
}