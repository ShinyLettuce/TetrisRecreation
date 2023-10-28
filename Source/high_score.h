#pragma once
#include "raylib.h"
#include "level.h"
#include <iostream>
#include <algorithm>
#include <vector>

struct High_Score_Entry 
{
	char name[4] = {};
	int score = 0;

	bool operator > (const High_Score_Entry& stru) const
	{
		return (score > stru.score);
	}
};

struct High_Score_List
{
	std::vector<High_Score_Entry> list = {};
	const int list_size = 5;
	char name[4] = "\0";
	int letter_count = 0;

	bool score_saved = false;


	void init();

	void enter_name_update(int score);
	void list_showcase_update();
	void render(int score);
};
