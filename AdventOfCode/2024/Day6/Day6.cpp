#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::ifstream input("input.txt");
std::string str;

class Guard
{
    public:

    std::vector<std::vector<int>> map;
    
    int rot = 0;
    std::pair<int, int> curLoc;
    std::pair<int, int> nextLoc;

    Guard(int x, int y, std::vector<std::vector<int>> m)
    {
        curLoc = std::pair<int, int>(x, y);
        nextLoc = findNextLoc();
        map = m;
    }

    void turn()
    {
        rot++;
        std::cout << "rot called and is now: " << rot << '\n';
        if (rot == 4)
        {
            rot = 0;
        }
    }

    std::pair<int, int> findNextLoc()
    {
        switch (rot)
        {
        case 0:
            return std::pair<int, int>(curLoc.first, curLoc.second - 1);
            break;
        case 1:
            return std::pair<int, int>(curLoc.first + 1, curLoc.second);
            break;
        case 2:
            return std::pair<int, int>(curLoc.first, curLoc.second + 1);
            break;
        case 3:
            return std::pair<int, int>(curLoc.first - 1, curLoc.second);
            break;
        default:
            std::cout << "error, no rotation specified" << '\n';
            return curLoc;
            break;
        }
    }

    void step()
    {
        nextLoc = findNextLoc();

        if (!(nextLoc.second < 0 || nextLoc.second > map.size() || nextLoc.first < 0 || nextLoc.first > map[nextLoc.second].size()))
        {
            if (map[nextLoc.second][nextLoc.first] == 2)
            {
                turn();
                nextLoc = findNextLoc();
            }
        }
        
        curLoc = nextLoc;

        if (curLoc.first >= 0 && curLoc.first < map[0].size() && curLoc.second >= 0 && curLoc.second < map.size())
        {
            map[curLoc.second][curLoc.first] = 1;
        }
    }

    bool isInMap()
    {
        return !(curLoc.second < 0 || curLoc.second > map.size() || curLoc.first < 0 || curLoc.first > map[curLoc.second].size());
    }
};

std::vector<std::vector<int>> createMap()
{
    std::vector<std::vector<int>> map = std::vector<std::vector<int>>();
    int index = 0;

    while (getline(input, str))
    {
        map.push_back(std::vector<int>());
        for (auto c : str)
        {
            if (c == '.')
            {
                map[index].push_back(0);
            }
            if (c == '^')
            {
                map[index].push_back(1);
            }
            if (c == '#')
            {
                map[index].push_back(2);
            }
        }
        
        index++;
    }

    return map;
}

void Part1()
{
    int xCoord = 0;
    int yCoord = 0;
    int total = 0;
    std::vector<std::vector<int>> labMap = createMap();
    for (int y = 0; y < labMap.size(); y++)
    {
        for (int x = 0; x < labMap[y].size(); x++)
        {
            if (labMap[y][x] == 1)
            {
                xCoord = x;
                yCoord = y;
                
            }
        }
    }
    Guard labGuard(xCoord, yCoord, labMap);

    while (labGuard.isInMap())
    {
        labGuard.step();
    }
    std::cout << "guard left lab" << '\n';
    labMap = labGuard.map;

    for (int i = 0; i < labMap.size(); i++)
    {
        for (int k = 0; k < labMap[i].size(); k++)
        {
            if (labMap[i][k] == 1)
            {
                total++;
            }
        }
    }

    std::cout << "Guard visits a total of: " << total << " positions";
}

void Part2()
{

}

int main()
{
    if (!input.is_open())
    {
        return 1;
    }
    Part1();
    return 0;
}