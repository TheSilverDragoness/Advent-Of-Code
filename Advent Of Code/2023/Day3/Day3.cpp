#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void part1()
{
	std::ifstream input("input.txt");
	std::string str;

	std::pair<int, double> valpos;
	std::vector<std::pair<int, double>> linevals;
	std::vector<std::vector<std::pair<int, double>>> linenums;

	int row = 0, column = 0;
	if (input.is_open())
	{
		while (getline(input, str))
		{
			row++;
			std::cout << str << std::endl;

			for (int i = 0; i < str.length(); i++)
			{
				if (!isalnum(str[i]))
				{
					column = i;
					std::pair<std::pair<int, int>, int>> coord;
				}
			}
		}
	}
}

void part2()
{
	std::ifstream input("input.txt");
	std::string str;

	if (input.is_open())
	{

	}
}

int main()
{
	part1();
	return 0;
}