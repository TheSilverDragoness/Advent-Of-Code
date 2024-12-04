#include <iostream>
#include <fstream>
#include <string>

std::ifstream input("input.txt");
std::string str;

void Part1()
{
    while (getline(input, str))
    {
        /*
        Separate into
            name
            SectorID
            checksum
        
        Tally all chars

        Sort by commonality
        Sort within same commonality alphabetically
            Only keep first 5

        check if matches checksum
            if yes, then add sector ID to total
        */
    }
}

void Part2()
{
    while (getline(input, str))
    {
        
    }
}

int main()
{
    if (!input.is_open())
    {
        std::cout << "input did not open";
        return 1;
    }
    Part1();
    return 0;
}