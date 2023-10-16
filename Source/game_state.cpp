#include "game_state.h"

void Game_State::game_screen()
{
	level.update();
	menu_render();
	level.render();

	if (level.lock_out)
	{
		game_state.pop();
		level.score = 0;
	}
}

void Game_State::menu_screen()
{
	menu_render();

	if (IsKeyDown(KEY_X)) //change button
	{
		level.init();
		game_state.push(Game_State::GAME_STATE::GAME_SCREEN);
	}
}

void Game_State::menu_render()
{
	DrawTexture(Media::sky, 0, 0, WHITE);
	DrawTexture(Media::lake, 0, 10, WHITE);
	DrawTexture(Media::clouds, static_cast<int>(cloud_pos.x), static_cast<int>(cloud_pos.y), WHITE);
	DrawTexture(Media::clouds, static_cast<int>(cloud_pos2.x), static_cast<int>(cloud_pos2.y), WHITE);
	DrawTexture(Media::hills, static_cast<int>(hill_pos.x), static_cast<int>(hill_pos.y), WHITE);
	DrawTexture(Media::hills, static_cast<int>(hill_pos2.x), static_cast<int>(hill_pos2.y), WHITE);
	DrawTexture(Media::pole, static_cast<int>(pole_pos.x), static_cast<int>(pole_pos.y), WHITE);
	DrawTexture(Media::car, static_cast<int>(car_pos.x), static_cast<int>(car_pos.y), WHITE);
	DrawTexture(Media::title, 40, 500, WHITE);

	DrawText("press x to start", 490, 700, 36, WHITE);
	DrawText("press c to test", 490, 750, 36, WHITE);

	car_counter++;
	cloud_counter++;
	hill_counter++;
	pole_counter++;

	if (pole_counter >= 40)
	{
		pole_pos.x = 80;
	}
	if (pole_counter >= 47)
	{
		pole_pos.x = 600;
	}
	if (pole_counter >= 54)
	{
		pole_pos.x = 1000;
		pole_counter = 0;
	}

	if (cloud_counter >= 4)
	{
		cloud_pos.x++;
		cloud_pos2.x++;

		cloud_counter = 0;
	}

	if (hill_counter >= 4)
	{
		hill_pos.x += 4;
		hill_pos2.x += 4;

		hill_counter = 0;
	}

	if (hill_pos.x >= 810)
	{
		hill_pos.x = -1190;
	}
	if (hill_pos2.x >= 810)
	{
		hill_pos2.x = -1190;
	}

	if (cloud_pos.x >= 810)
	{
		cloud_pos.x = -1190;
	}
	if (cloud_pos2.x >= 810)
	{
		cloud_pos2.x = -1190;
	}

	if (car_counter >= 20)
	{
		car_pos.y = 0;
	}
	if (car_counter >= 90)
	{
		car_pos.y = 20;
		car_counter = 0;
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