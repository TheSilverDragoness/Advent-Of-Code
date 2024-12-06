#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>

std::ifstream input("input.txt");
std::string str;

bool checkSequence(std::multimap<int, int> rules, std::vector<int> pageSeq)
{
    for (int i = 1; i < pageSeq.size(); i++)
    {
        if (rules.find(pageSeq[i]) == rules.end())
        {
            continue;
        }
        for (int k = i-1; k >= 0; k--)
        {
            auto range = rules.equal_range(pageSeq[i]);
            for (auto j = range.first; j != range.second; j++)
            {
                if (pageSeq[k] == j->second)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

std::vector<int> moveInt(std::vector<int> vect, int a, int b)
{
    std::vector<int> copy = vect;
    int num = copy[a];
    copy.erase(copy.begin()+a);
    copy.insert(copy.begin() + b, num);

    return copy;
}

std::vector<int> reOrderList(std::multimap<int, int> rules, std::vector<int> pageSeq)
{
    std::vector<int> copyList = pageSeq;
    std::vector<int> newList = pageSeq;

    while (!checkSequence(rules, copyList))
    {
        for (int i = copyList.size()-1; i > 0; i--)
        {
            if (rules.find(pageSeq[i]) == rules.end())
            {
                continue;
            }
            for (int k = i-1; k >= 0; k--)
            {
                auto range = rules.equal_range(pageSeq[i]);
                for (auto j = range.first; j != range.second; j++)
                {
                    if (pageSeq[k] == j->second)
                    {
                        newList = moveInt(copyList, i, k);
                    }
                }
            }
        }
        copyList = newList;
    }
    return copyList;
}

//TRY TOPOLOGICAL SORTING

void Part1()
{
    std::regex reg(R"((\d+)\|(\d+))");
    std::regex regDig(R"((\d+))");
    std::multimap<int, int> rules;
    std::vector<std::vector<int>> pages = std::vector<std::vector<int>>();
    std::smatch match;
    int index = 0;
    int total = 0;

    while(getline(input,str))
    {
        if (std::regex_search(str, match, reg))
        {
            rules.insert(std::make_pair(stoi(match[1]), stoi(match[2])));
        }
        else 
        {
            pages.push_back(std::vector<int>());
            while(std::regex_search(str, match, regDig))
            {
                pages[index].push_back(stoi(match.str()));
                str = match.suffix().str();
            }
            index++;
        }
    }

    for (auto v : pages)
    {
        if (checkSequence(rules, v))
        {
            total += v[(v.size()/2)];
        }
    }

    std::cout << "total: " << total;
}

void Part2()
{
    std::regex reg(R"((\d+)\|(\d+))");
    std::regex regDig(R"((\d+))");
    std::multimap<int, int> rules;
    std::vector<std::vector<int>> pages = std::vector<std::vector<int>>();
    std::smatch match;
    int index = 0;
    int index2 = 0;
    int total = 0;

    while(getline(input,str))
    {
        if (std::regex_search(str, match, reg))
        {
            rules.insert(std::make_pair(stoi(match[1]), stoi(match[2])));
        }
        else 
        {
            pages.push_back(std::vector<int>());
            while(std::regex_search(str, match, regDig))
            {
                pages[index].push_back(stoi(match.str()));
                str = match.suffix().str();
            }
            index++;
        }
    }

    for (auto v : pages)
    {
        index2++;
        if (!checkSequence(rules, v))
        {
            std::cout << "Re Ordering list " << index2 << " out of " << pages.size() << '\n';
            std::vector<int> correctList = reOrderList(rules, v);
            total += correctList[correctList.size()/2];
        }
    }

    std::cout << "total: " << total;
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