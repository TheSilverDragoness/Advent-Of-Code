#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "timer.h"

std::ifstream input("input.txt");
std::string str;
std::string deliminator = " ";
std::vector<int> list1;
std::vector<int> list2;

bool check(size_t pos)
{
	return pos != std::string::npos;
}

std::vector<int> tokenise(const std::string& inputStr, const std::string& del)
{
	std::vector<int> tokens;

	size_t startPos;
	size_t endPos = 0;

	while (check(startPos = inputStr.find_first_not_of(del, endPos)))
	{
		endPos = inputStr.find_first_of(del, startPos);
		tokens.push_back(stoi(inputStr.substr(startPos, endPos - startPos)));
	}

	return tokens;
}

void Part1()
{
    Timer timer;
    timer.Reset();
    int distance = 0;
    while (getline(input, str))
    {
        std::vector<int> tempVect = tokenise(str, deliminator);
        list1.push_back(tempVect[0]);
        list2.push_back(tempVect[1]);
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    for (int i = 0; i < list1.size(); i++)
    {
        distance += abs(list1[i] - list2[i]);
    }

    float time = timer.Elapsed();
    std::cout << "Distance = " << distance << " Elapsed time (s): " << time << '\n';
}

void Part2()
{
    Timer timer;
    timer.Reset();
    std::vector<int> appearaces;
    int index = 0;
    int similarityScore = 0;

    while (getline(input, str))
    {
        std::vector<int> tempVect = tokenise(str, deliminator);
        list1.push_back(tempVect[0]);
        list2.push_back(tempVect[1]);
    }

    for (auto b : list1)
    {
        appearaces.push_back(0);
        for (auto v : list2)
        {
            if (b == v)
            {
                appearaces[index]++;
            }   
        }
        index++;
    }

    for (int i = 0; i < list1.size(); i++)
    {
        similarityScore += (list1[i] * appearaces[i]);
    }

    float time = timer.Elapsed();
    std::cout << "Similarity Score = " << similarityScore << " Elapsed time (s): " << time << '\n'; 
}

int main()
{
    if (!input.is_open())
    {
        std::cout << "input is not open";
        return 1;
    }
    Part1();
    Part2();
    return 0;
}

