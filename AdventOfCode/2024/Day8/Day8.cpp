#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

std::ifstream input("input.txt");
std::string str;

void Part1()
{
    std::vector<std::vector<char>> grid;
    std::multimap<char, std::pair<int, int>> antennas;
    std::vector<std::pair<int, int>> antiNodes;

    int ycoord = 0;
    int xcoord = 0;

    while (getline(input, str))
    {
        for (auto c : str)
        {
            if (c == '.')
            {
                xcoord++;
                continue;
            }

            antennas.emplace(c, std::make_pair(xcoord, ycoord));
            xcoord++;
        }
        ycoord++;
    }

    for (auto m : antennas)
    {
        //for every type of antenna, look at each pair of antennas
        //using find the position of the antinodes
        //check whether they are in the list of existing antinodes
        //if no, then check whether they are within the bounds of the map
        //if yes, then add to list
    }

    std::cout << "Number of antinodes: " << antiNodes.size();
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
        std::cout << "input is not open";
        return 1;
    }
    Part1();
    return 0;
}

//create antenna class
//  Includes type (char), and location (pair)

//walk through map, for each antenna type, check if already encountered, if not, add it to a vector of types
//new vector for each different antenna, stores each location
//for each pair of antenna, calculate each location of antinode
//if location in map, and not in vector of existing antinodes then add it to vector of antinodes;

