#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "timer.h"


std::ifstream input("input.txt");
std::string str;
std::string deliminator = " "; 

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

    std::vector<int> intList;
    int safeReports = 0;
    while (getline(input,str))
    {
        bool firstCheck = true;
        bool isIncreasing;
        bool isValid;
        intList = tokenise(str, deliminator);

        for (int i = 0; i < intList.size() - 1; i++)
        {
            int a = intList[i];
            int b = intList[i + 1];

            if (firstCheck)
            {
                isIncreasing = (a < b);
                firstCheck = false;
            }

            isValid = ((a < b) == isIncreasing && abs(a - b) <= 3 && abs(a - b) > 0);

            if (!isValid)
            {
                break;
            }
        }
        if (isValid)
        {
            safeReports++;
        }
    }
    float time = timer.Elapsed();
    std::cout << "Safe reports: " << safeReports << " Elapsed time (s): " << time << '\n';
}

bool CheckReport(std::vector<int> intList)
{
    bool isValid = true;
    bool firstCheck = true;
    bool isIncreasing;

    //std::cout << "Processing list of size: " << intList.size() << '\n';
    if (intList.size() < 2)
    {
        return true;
    }
    for (int k = 0; k < intList.size() - 1;k++)
    {
        int a = intList[k];
        int b = intList[k + 1];

        if (firstCheck)
        {
            isIncreasing = (a < b);
            firstCheck = false;
        }

        isValid = ((a < b) == isIncreasing && abs(a - b) <= 3 && abs(a - b) > 0);

        if (!isValid)
        {
            break;
        }
    }
    return isValid;
}

void Part2()
{
    Timer timer;
    timer.Reset();

    int safeReports = 0;
    std::vector<std::vector<int>> reports;

    while (getline(input, str))
    {
        reports.push_back(tokenise(str, deliminator));
    }

    for (auto reportList : reports)
    {
        if (CheckReport(reportList))
        {
            safeReports++;
            continue;
        }
        else
        {
            for (int i = 0; i < reportList.size(); i++)
            {
                std::vector<int> reportCopy = reportList;
                reportCopy.erase(reportCopy.begin() + i);
                if (CheckReport(reportCopy))
                {
                    safeReports++;
                    break;
                }
            }
        }
    }
    
    float time = timer.Elapsed();
    std::cout << "Safe reports: " << safeReports << " Elapsed time (s): " << time << '\n';
}

int main()
{
    if (!input.is_open())
    {
        std::cout << "Input did not open correctly";
        return 1;
    }
    Part2();
    return 0;
}