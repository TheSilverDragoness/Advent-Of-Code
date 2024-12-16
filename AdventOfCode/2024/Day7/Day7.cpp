#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <cmath>

std::ifstream input("input.txt");
std::string str;

uint64_t getTargetNum(std::string s)
{
    uint64_t num = 0;
    std::regex reg(R"((\d+):)");
    std::smatch match;

    if (std::regex_search(str, match, reg))
    {
        num = stoll(match[1]);
    }

    return num;
}

std::vector<uint64_t> getValues(std::string s)
{
    std::vector<uint64_t> vals;
    std::regex reg(R"((\d+))");
    std::smatch match;

    auto begin = std::sregex_iterator(str.begin(), str.end(), reg);
    auto end = std::sregex_iterator();
    if (begin != end)
    {
        ++begin;
    }
    for (auto it = begin; it != end; ++it)
    {
        vals.push_back(std::stoll(it->str()));
    }
    return vals;
}

void Part1()
{
    uint64_t total = 0;

    while (getline(input, str))
    {
        uint64_t targetNum = 0;
        uint64_t runningSum = 0;
        std::vector<uint64_t> values;
        std::vector<int> operations;

        targetNum = getTargetNum(str);
        values = getValues(str);

        uint32_t binVal = pow(2, values.size());
        //std::cout << binVal << '\n';;
        for (uint32_t b = 0; b < binVal; b++)
        {
            runningSum = 0;
            operations.clear();
            uint32_t current = b;

            while (current > 0)
            {
                operations.push_back(current & 1);
                current >>= 1;
            }
            while (operations.size() < values.size())
            {
                operations.push_back(0);
            }

            std::reverse(operations.begin(), operations.end());

            runningSum = values[0];

            for (int i = 0; i < values.size()-1; i++)
            {
                if (operations[i] == 1)
                {
                    runningSum += values[i+1];
                }
                else
                {
                    runningSum *= values[i+1];
                }
            }

            if (runningSum == targetNum)
            {
                total += targetNum;
                break;
            }
        }
    }

    std::cout << "total: " << total;
}

void Part2()
{
    uint64_t total = 0;
    int index = 0;

    while (getline(input, str))
    {
        index++;
        float progress = float(float(float(index)/850) * 100);
        std::cout << "Working on line " << index << " out of 850... " << progress << "%..." << '\n';
        uint64_t targetNum = 0;
        uint64_t runningSum = 0;
        std::vector<uint64_t> values;
        std::vector<int> operations;

        targetNum = getTargetNum(str);
        values = getValues(str);

        uint32_t terVal = pow(3, values.size());

        for (uint32_t b = 0; b < terVal; b++)
        {
            runningSum = 0;
            operations.clear();
            uint32_t current = b;

            while (current > 0)
            {
                operations.push_back(current % 3);
                current /= 3;
            }
            while (operations.size() < values.size())
            {
                operations.push_back(0);
            }

            runningSum = values[0];

            for (int i = 0; i < values.size()-1; i++)
            {
                if (operations[i] == 0)
                {
                    runningSum += values[i+1];
                }
                else if (operations[i] == 1)
                {
                    runningSum *= values[i+1];
                }
                else if (operations[i] == 2)
                {
                    uint64_t temp = runningSum;
                    std::string s = std::to_string(temp);
                    std::string t = std::to_string(values[i+1]);
                    std::string st = s.append(t);
                    runningSum = std::stoll(st);
                }
            }

            if (runningSum == targetNum)
            {
                total += targetNum;
                break;
            }
        }
    }

    std::cout << "total: " << total;
}

int main()
{
    if (!input.is_open())
    {
        std::cout << "error opening input" << '\n';
        return 1;
    }
    Part2();
    return 0;
}