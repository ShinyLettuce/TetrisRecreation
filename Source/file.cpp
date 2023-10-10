#include "file.h"

void File_Manager::load()
{
    stream.open(level_file);
}

void File_Manager::write(std::string text)
{
    std::ofstream myfile;
    myfile.open(".\\Assets\\Text\\example.txt");
    myfile << text;
    myfile.close();
}