#pragma once
#include <fstream>
#include <filesystem>
#include <string>
#include <iostream>

struct File_Manager {
    const char* level_file = "../Assets/Text/Levels.txt"; //ENI note: ../ => goes to the previous folder

    std::string read_high_score();
    void write_high_score(std::string new_score);
};