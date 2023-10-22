#include "game_state.h"

void Game_State::game_screen()
{
	level.update();
	menu.update();
	menu.render();
	level.render();

	if (level.lock_out)
	{
		game_state.pop();
		level.score = 0;
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

	if (IsKeyDown(KEY_X)) //change button
	{
		level.init();
		game_state.push(Game_State::GAME_STATE::GAME_SCREEN);
	}
	if (IsKeyDown(KEY_C)) //change button
	{
		level.init();
		game_state.push(Game_State::GAME_STATE::COLLISION_SCREEN);
	}
}

void Game_State::high_score_screen()
{

}

void Game_State::collision_screen()
{
	collision.update();
	collision.render();
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
		collision_screen();
		break;
	}
}