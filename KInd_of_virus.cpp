// KInd_of_virus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <filesystem>


using std::string;
using std::cout;
using std::cin;
using std::fstream;


void replicant(string s)
{
    std::ofstream dest("copy.cpp");
    if (dest.is_open()) 
    {
        dest << s;
        dest.close();
    }
    else
    {
        std::cerr << "Epic fail in replicant! Can't create a copy!";
    }
}

void worm(string path)
{
    for (const auto& file : std::filesystem::directory_iterator(path))
    {
        cout << file.path() << "\n";
    }
}


int main()
{
    string dir, source, tmp;
    cout << "Input destination folder: ";
    cin >> dir;
    fstream src("KInd_of_virus.cpp", std::ios::in);
    if (src.is_open())
    {
        while (std::getline(src, tmp))
        {
            source += tmp;
            source += "\n";
        }
        src.close();
    }
    else
    {
        std::cerr << "Epic fail! Can not open the file!\n";
    }
    replicant(source);
    worm(dir);
    cout << source;
}

