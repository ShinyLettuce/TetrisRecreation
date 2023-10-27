#include "file.h"

std::string File_Manager::read_high_score()
{
	std::ifstream score_list(".\\Assets\\text\\highscore.txt");
	std::string high_score;
	std::string line;
	if (score_list.is_open())
	{
		while (std::getline(score_list, line))
		{
			high_score += line + "\n";
		}

		score_list.close();
		return high_score;
	}
	else
	{
		std::cout << "Unable to open high score file";
		return NULL;
	}
}

void File_Manager::write_high_score(int new_score)
{
	std::ofstream score_list(".\\Assets\\text\\highscore.txt");
	std::string score;
	score = std::to_string(new_score);

	if (score_list.is_open())
	{
		score_list << score + "\n";
	}
	else
	{
		std::cout << "Unable to open high score file";
	}

}