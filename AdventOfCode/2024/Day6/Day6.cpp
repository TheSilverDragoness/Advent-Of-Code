#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::ifstream input("input.txt");
std::string str;

class Guard
{
    public:
    std::vector<std::pair<int, int>> visitedPositions;
    std::vector<std::pair<std::pair<int, int>, int>> turnCoords;
    std::vector<std::vector<int>> map;
    
    bool looping = false;
    int counter = 0;
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
        //looping = isLooping();
        //turnCoords.push_back(std::pair<std::pair<int, int>, int>(curLoc, rot));
        
        rot++;
        //std::cout << "rot called and is now: " << rot << '\n';
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
        //std::cout << "current loc: " << curLoc.first << ", " << curLoc.second << '\n';

        if ((nextLoc.second < 0 || nextLoc.second >= map.size() || nextLoc.first < 0 || nextLoc.first >= map[nextLoc.second].size()))
        {
            curLoc = nextLoc;
            return;
        }

        while (map[nextLoc.second][nextLoc.first] > 1)
        {
            turn();
            nextLoc = findNextLoc();

            // Ensure boundaries after turning
            if (nextLoc.second < 0 || nextLoc.second >= map.size() ||  nextLoc.first < 0 || nextLoc.first >= map[nextLoc.second].size())
            {  
                curLoc = nextLoc;
                return;
            }
        }

        curLoc = nextLoc;
        if (std::find(visitedPositions.begin(), visitedPositions.end(), curLoc) == visitedPositions.end())
        {
            visitedPositions.push_back(curLoc);
        }
        if (curLoc.first >= 0 && curLoc.first < map[0].size() && curLoc.second >= 0 && curLoc.second < map.size())
        {
            map[curLoc.second][curLoc.first] = 1;
        }
    }

    bool isLooping()
    {
        counter++;
        if (counter > 9999)
        {
            return true;
        }

        for (const auto& coord : turnCoords)
        {
            if (coord.first == curLoc && coord.second == rot)
            {
                return true;
            }
        }
        return false;
    }

    bool isInMap()
    {
        //std::cout << map.size() << ", " << map[curLoc.second].size() << '\n';
        //std::cout << "Is In Map: " << std::boolalpha << !(curLoc.second < 0 || curLoc.second > map.size() || curLoc.first < 0 || curLoc.first > map[curLoc.second].size()) << '\n';
        return !(curLoc.second < 0 || curLoc.second > map.size() || curLoc.first < 0 || curLoc.first > map[curLoc.second].size());
    }
};

std::vector<std::vector<int>> createMap()
{
    std::vector<std::vector<int>> map;
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

    std::vector<std::pair<int, int>> positions = labGuard.visitedPositions;

    for (const auto& v : positions)
    {
        //std::cout << v.first << ", " << v.second << '\n';
        if (labMap[v.second][v.first] > 1)
        {
            continue;
        }

        std::vector<std::vector<int>> mapCopy = labMap;

        mapCopy[v.second][v.first] = 2;

        Guard newlabGuard(xCoord, yCoord, mapCopy);
        while (newlabGuard.isInMap())
        {
            if (newlabGuard.isLooping())
            {
                total++;
                break;
            }
            newlabGuard.step();
        }
    }

    std::cout << "total: " << total;
}

int main()
{
    if (!input.is_open())
    {
        return 1;
    }
    Part2();
    return 0;
}