#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <map>

void Part1()
{
    std::ifstream input("input.txt");
    std::string str;

    std::string bathroomCode;
    int tempKeypadNum = 5;
    if (input.is_open())
    {
        while(getline(input, str))
        {
            int strSize = str.length();
            char currentChar;

            for (int i = 0; i < strSize; i++)
            {
                currentChar = str[i];
                //std::cout << currentChar;
                switch (currentChar)
                {
                case 'U':
                    if (tempKeypadNum == 1 || tempKeypadNum == 2 || tempKeypadNum == 3)
                        break;
                    tempKeypadNum -= 3;
                    break;
                case 'D':
                    if (tempKeypadNum == 7 || tempKeypadNum == 8 || tempKeypadNum == 9)
                        break;
                    tempKeypadNum += 3;
                    break;
                case 'L':
                    if (tempKeypadNum == 1 || tempKeypadNum == 4 || tempKeypadNum == 7)
                        break;
                    tempKeypadNum--;
                    break;
                case 'R':
                    if (tempKeypadNum == 3 || tempKeypadNum == 6 || tempKeypadNum == 9)
                        break;
                    tempKeypadNum++;
                    break;
                default:
                    std::cout << "Switch Error, char not recognised";
                    break;
                }
            }
            //std::cout << '\n';
            bathroomCode.append(std::to_string(tempKeypadNum));
        }

        std::cout << "Bathroom code is: " << bathroomCode;
    }
}

void Part2()
{
    std::ifstream input("input.txt");
    std::string str;

    std::string bathroomCode;
    int tempKeypadNum = 5;

    int xcoord = 0;
    int ycoord = 2;

    typedef std::pair<int, int> pii;

    std::unordered_map<char, pii> dir;

    dir['U'] = {-1, 0};
    dir['D'] = {1, 0};
    dir['L'] = {0, -1};
    dir['R'] = {0, 1};

    std::map<pii, char> keypad;

    keypad[{0, 2}] = '1';
    keypad[{1, 1}] = '2';
    keypad[{1, 2}] = '3';
    keypad[{1, 3}] = '4';
    keypad[{2, 0}] = '5';
    keypad[{2, 1}] = '6';
    keypad[{2, 2}] = '7';
    keypad[{2, 3}] = '8';
    keypad[{2, 4}] = '9';
    keypad[{3, 1}] = 'A';
    keypad[{3, 2}] = 'B';
    keypad[{3, 3}] = 'C';
    keypad[{4, 2}] = 'D';
    
    if (!input.is_open())
    {
        std::cout << "File Not Open";
        return;
    }
    while (getline(input,str))
    {
        for (char c : str)
        {
            if (keypad.count( {xcoord + dir[c].first, ycoord + dir[c].second}))
            {
                xcoord += dir[c].first;
                ycoord += dir[c].second;
            }
        }
        bathroomCode.push_back(keypad[{xcoord, ycoord}]);
    }

    std::cout << "The bathroom code is: " << bathroomCode;
}

int main()
{
    Part2();
    return 0;
}
