#pragma once
#include <string>
#include <vector>

struct High_Score_Entry 
{
	std::string name;
	int score;
};

struct High_Score_List
{
	std::vector<High_Score_Entry> list = {};
};
