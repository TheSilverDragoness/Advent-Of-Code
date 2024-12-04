#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::ifstream input("input.txt");
std::string str;

bool isXmas (char b, char c, char d)
{
    return (b == 'M' && c == 'A' && d == 'S');
}

int xmasSearch(std::vector<std::vector<char>> grid, int y, int x)
{
    int count = 0;

    if (x > 2 && y > 2)
    {
        if (isXmas(grid[y-1][x-1], grid[y-2][x-2], grid[y-3][x-3]))
        {
            count++;
        }
    }
    if (x < grid[y].size()-3 && y < grid.size()-3)
    {
        if (isXmas(grid[y+1][x+1], grid[y+2][x+2], grid[y+3][x+3]))
        {
            count++;
        }
    }
    if (x > 2 && y < grid.size()-3)
    {
        if (isXmas(grid[y+1][x-1], grid[y+2][x-2], grid[y+3][x-3]))
        {
            count++;
        }
    }
    if (x < grid[y].size()-3)
    {
        if (isXmas(grid[y][x+1], grid[y][x+2], grid[y][x+3]))
        {
            count++;
        }
    }
    if (x > 2)
    {
        if (isXmas(grid[y][x-1], grid[y][x-2], grid[y][x-3]))
        {
            count++;
        }
    }
    if (y < grid.size()-3)
    {
        if (isXmas(grid[y+1][x], grid[y+2][x], grid[y+3][x]))
        {
            count++;
        }
    }
    if (y > 2)
    {
        if (isXmas(grid[y-1][x], grid[y-2][x], grid[y-3][x]))
        {
            count++;
        }
    }
    if (x < grid[y].size()-3 && y > 2)
    {
        if (isXmas(grid[y-1][x+1], grid[y-2][x+2], grid[y-3][x+3]))
        {
            count++;
        }
    }
    return count;
}

void Part1()
{
    std::vector<std::vector<char>> grid;
    
    int inputIndexY = 0;
    int total = 0;

    while (getline(input, str))
    {
        grid.push_back(std::vector<char>());
        for (auto c : str)
        {
            grid[inputIndexY].push_back(c);
        }
        inputIndexY++;
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int k = 0; k < grid[i].size(); k++)
        {
            if (grid[i][k] != 'X')
            {
                continue;
            }
            total += xmasSearch(grid, i, k);
        }
    }

    std::cout << "total: " << total;
}

bool isMas (std::vector<std::vector<char>> grid, int y, int x)
{
    if ((grid[y-1][x-1] == 'M' && grid[y+1][x+1] == 'S') || (grid[y-1][x-1] == 'S' && grid[y+1][x+1] == 'M'))
    {
        if((grid[y-1][x+1] == 'M' && grid[y+1][x-1] == 'S') || (grid[y-1][x+1] == 'S' && grid[y+1][x-1] == 'M'))
        {
            return true;
        }
    }
    return false;
}

void Part2()
{
    std::vector<std::vector<char>> grid;
    
    int inputIndexY = 0;
    int total = 0;

    while (getline(input, str))
    {
        grid.push_back(std::vector<char>());
        for (auto c : str)
        {
            grid[inputIndexY].push_back(c);
        }
        inputIndexY++;
    }
    for (int i = 1; i < grid.size()-1; i++)
    {
        for (int k = 1; k < grid[i].size()-1; k++)
        {
            if (grid[i][k] != 'A')
            {
                continue;
            }
            if (isMas(grid, i, k))
            {
                total ++;
            }
        }
    }
    std::cout << "total: " << total;
}

int main()
{
    if (!input.is_open())
    {
        std::cout << "input.txt did not open";
        return 1;
    }
    Part2();
    return 0;
}