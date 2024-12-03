#include <iostream>
#include <fstream>
#include <string>
#include <regex>

std::ifstream input("input.txt");
std::string str;

void Part1() 
{
    int total = 0;
    std::smatch match;
    
    std::regex reg(R"(mul\((\d+)+,(\d+)+\))");
    
    while (getline(input, str))
    {
        while (std::regex_search(str, match, reg))
        {
            int a = std::stoi(match[1].str());
            int b = std::stoi(match[2].str());
            total += a * b;
            str = match.suffix().str();
        }
    }

    std::cout << "part 1: " << total << '\n';
}

void Part2()
{
    bool enableMul = true;
    int total = 0;
    std::smatch match;

    std::regex reg(R"(mul\((\d+)+,(\d+)+\))");
    std::regex enable(R"(do\(\))");
    std::regex disable(R"(don't\(\))");
    std::regex combined(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
    
    while (getline(input, str))
    {
        while (std::regex_search(str, match, combined))
        {
            if (!enableMul && std::regex_match(match.str(), enable))
            {
                enableMul = true;
                continue;
            }
            else if (enableMul && std::regex_match(match.str(), disable))
            {
                enableMul = false;
                continue;
            }
            else if (enableMul && std::regex_match(match.str(), reg))
            {
                int a = std::stoi(match[1].str());
                int b = std::stoi(match[2].str());
                total += a * b;
            }
            str = match.suffix().str();
        }
    }

    std::cout << "part 2: " << total;
}

int main()
{
    if (!input.is_open())
    {
        std::cout << "input did not open";
        return 1;
    }
    Part2();
    return 0;
}