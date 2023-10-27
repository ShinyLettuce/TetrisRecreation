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
		game_state.push(Game_State::GAME_STATE::COLLISION_SCREEN);
	}
}

void Game_State::high_score_screen()
{
	High_Score_Entry e;
	e.name = "QQQ";
    e.score = level.score;
	//high_score.list.push_back(e);

	for (int i = 0; i < high_score.list.size(); i++)
	{
		if (e.score < level.score)
		{
			high_score.list.insert(high_score.list.begin() + i, e);
		}
	}

	for (High_Score_Entry n : high_score.list)
	{
		std::cout << e.name;
		std::cout << e.score;
	}
	game_state.pop();
	game_state.pop();
	//DrawText("High Score screen", 100, 100, 60, WHITE);
	//DrawText(TextFormat("%i", level.score), 100, 250, 60, WHITE);

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
		high_score_screen();
		break;
	case GAME_STATE::COLLISION_SCREEN:
		collision_screen();
		break;
	}
}