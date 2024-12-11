#include <iostream>
#include <fstream>
#include <string>
#include <regex>

std::ifstream input("input.txt");
std::string str;

uint32_t getTargetNum(std::string s)
{
    uint32_t num = 0;
    std::regex reg(R"((\d+):)");
    std::smatch match;

    if (std::regex_search(str, match, reg))
    {
        num = stoll(match[1]);
    }

    return num;
}

std::vector<int> getValues(std::string s)
{
    std::vector<int> vals;
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
        vals.push_back(std::stoi(it->str()));
    }
    return vals;
}

int addNums(int a, int b)
{
    int add = a + b;
    return add;
}
int mulNums(int a , int b)
{
    int mul = a * b;
    return mul;
}

void Part1()
{
    int total;
    std::smatch matcht;
    std::smatch matchn;

    while (getline(input, str))
    {
        uint32_t targetNum = 0;
        uint32_t runningSum = 0;
        std::vector<int> values;

        targetNum = getTargetNum(str);
        values = getValues(str);

        std::cout << "target: " << targetNum << " | ";
        for (auto i : values)
        {
            std::cout << i << " ";
        }
        std::cout << '\n';

        //get binary num with size: values.size()-1
        //start from all zeroes and count up til all 1s
        //for 0, do addition
        //for 1, do multiplication
        //iterate through vector of values doing each operation and check against target val
        //if target val reached, add it to the total and move onto next line
    }
}

void Part2()
{

}

int main()
{
    if (!input.is_open())
    {
        std::cout << "error opening input" << '\n';
        return 1;
    }
    Part1();
    return 0;
}