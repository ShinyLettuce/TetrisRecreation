#include "file.h"

void File_Manager::load()
{
    stream.open(level_file);
}

void File_Manager::write()
{
    std::ofstream myfile;
    myfile.open(".\\Assets\\Text\\example.txt");
    myfile << "Let's burn this shit down, Jaakko.\n";
    myfile.close();
}