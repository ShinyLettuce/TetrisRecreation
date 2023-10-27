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
	std::stringstream ss;
	std::vector<int> scores = {};
	ss << file.read_high_score();

	for (int i = 0; i < 5; i++)
	{
		int num;
		ss >> num;
		scores.push_back(num);
	}

	std::cout << ss.str();

	for (int i = 0; i < scores.size(); i++)
	{
		if (level.score > scores[i])
		{
			scores.pop_back();
			scores.insert(scores.begin() + i, level.score);
			break;
		}
	}

	ss.str("");
	ss.clear();

	for (int s : scores)
	{
		ss << s << "\n";
	}
	
	file.write_high_score(ss.str());
	
	std::cout << file.read_high_score();

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