#pragma once
#include <fstream>
#include <filesystem>

struct File_Manager {
    const char* level_file = "../Assets/Text/Levels.txt"; //ENI note: ../ => goes to the previous folder

    std::fstream stream;

    void load();

    void write();
};