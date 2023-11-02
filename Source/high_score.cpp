#include "high_score.h"

void High_Score_List::init()
{
	letter_count = 0;
	score_saved = false;
}

void High_Score_List::enter_name_update(int score)
{
	int key = GetCharPressed();

	while (key > 0)
	{
		if ((key > 32) && (key <= 125) && letter_count < 3)
		{
			name[letter_count] = (char)key;
			name[letter_count + 1] = '\0';
			letter_count++;
		}

		key = GetCharPressed();
	}
	if (IsKeyPressed(KEY_BACKSPACE))
	{
		letter_count--;
		if (letter_count < 0)
		{
			letter_count = 0;
		}
		name[letter_count] = '\0';
	}

	if (letter_count == 3 && IsKeyPressed(KEY_ENTER))
	{
		High_Score_Entry e;
		
		for (int i = 0; i < 4; i++)
		{
			e.name[i] = name[i];
		}
		e.score = score;

		list.push_back(e);
		std::sort(list.begin(), list.end(), std::greater<High_Score_Entry>());
		if (list.size() > 5)
		{
			list.pop_back();
		}

		score_saved = true;
	}

}

void High_Score_List::render(int score)
{
	if (!score_saved)
	{
		DrawText("Write your name", 150, 200, 60, WHITE);
		DrawText(name, 200, 400, 80, WHITE);
		DrawText(TextFormat("%i", score), 450, 400, 80, WHITE);
		DrawText("press ENTER to submit", 50, 600, 60, WHITE);
	}
	else
	{
		ClearBackground({ 55,148,110 });
		DrawRectangle(0, 0, 50, 900, { 90, 90, 90, 255 });
		DrawRectangle(760, 0, 50, 900, { 90, 90, 90, 255 });
		DrawRectangle(0, 850, 810, 50, { 202, 201, 170, 255 });
		DrawRectangle(0, 0, 810, 80, { 202, 201, 170, 255 });

		DrawRectangle(0, 35, 200, 10, { 190, 70, 115, 255 });
		DrawRectangle(610, 35, 200, 10, { 190, 70, 115, 255 });
		DrawRectangle(0, 875, 480, 5, { 190, 70, 115, 255 });

		DrawText("HIGHSCORE", 220, 10, 64, DARKBLUE);
		DrawText("press T to exit", 500, 860, 30, DARKBLUE);
		for (int i = 0; i < list.size(); i++)
		{
			DrawText(list[i].name, 200, 130 + 150 * i, 80, { 26,100,70,255 });
			DrawText(TextFormat("%i", list[i].score), 450, 130 + 150 * i, 80, { 26,100,70,255 });
		}
	}
}