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
		if (letter_count < 0) letter_count = 0;
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

		for (High_Score_Entry n : list)
		{
			std::cout << n.name;
			std::cout << n.score;
		}

		score_saved = true;
	}

}

void High_Score_List::list_showcase_update()
{

}

void High_Score_List::render(int score)
{
	if (!score_saved)
	{
		DrawText(name, 200, 400, 80, WHITE);
		DrawText(TextFormat("%i", score), 450, 400, 80, WHITE);
	}
	else
	{

		for (int i = 0; i < list.size(); i++)
		{
			DrawText(list[i].name, 200, 100 + 150 * i, 80, WHITE);
			DrawText(TextFormat("%i", list[i].score), 450, 100 + 150 * i, 80, WHITE);
		}
	}
}