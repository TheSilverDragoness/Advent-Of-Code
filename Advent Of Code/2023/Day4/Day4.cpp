#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

void part1()
{
	std::ifstream input("input.txt");
	std::string str;
	std::string token;
	std::vector<int> win;
	std::vector<int> numbers;
	bool winset = true;
	int winnum = 0;

	int total = 0;

	if (input.is_open())
	{
		while (getline(input, str))
		{
			winnum = 0;
			winset = true;
			win.clear();
			numbers.clear();
			std::istringstream iss(str);
			while (iss >> token)
			{
				if (token[0] == '|')
				{
					winset = false;
				}
				else if (isdigit(token[0]) && (isdigit(token.back())))
				{
					if (winset)
					{
						win.push_back(stoi(token));
					}
					else if (!winset)
					{
						numbers.push_back(stoi(token));
					}
				}
			}
			for (int i = 0; i < win.size(); i++)
			{
				for (int k = 0; k < numbers.size(); k++)
				{
					if (win[i] == numbers[k])
					{
						winnum++;
					}
				}
			}

			std::cout << "number of winning numbers: " << winnum << std::endl;
				
			total += 1 * pow(2, winnum - 1);
		}
		std::cout << "total: " << total << std::endl;
	}
	input.close();
}

void part2()
{
	std::ifstream input("input.txt");
	std::string str;
	std::string token;
	std::vector<int> win;
	std::vector<int> numbers;
	std::vector<int> numofwins;
	std::vector<int> cardcopies;
	cardcopies.reserve(216);
	bool winset = true;
	int winnum = 0;
	int cardnum = 0;
	int total = 0;

	if (input.is_open())
	{
		while (getline(input, str))
		{
			winnum = 0;
			winset = true;
			win.clear();
			numbers.clear();
			std::istringstream iss(str);
			while (iss >> token)
			{
				if (token[0] == '|')
				{
					winset = false;
				}
				else if (isdigit(token[0]) && (isdigit(token.back())))
				{
					if (winset)
					{
						win.push_back(stoi(token));
					}
					else if (!winset)
					{
						numbers.push_back(stoi(token));
					}
				}
			}
			for (int i = 0; i < win.size(); i++)
			{
				for (int k = 0; k < numbers.size(); k++)
				{
					if (win[i] == numbers[k])
					{
						winnum++;
					}
				}
			}

			numofwins.push_back(winnum);
		}

		for (int a = 0; a < 216; a++)
		{
			cardnum++;
			cardcopies[cardnum + a] += cardcopies[cardnum] * numofwins[cardnum];
			
		}

		for (int b = 0; b < cardcopies.size(); b++)
			total += cardcopies[b];

		std::cout << "total: " << total << std::endl;
	}
	input.close();
}

int main()
{
	part2();
	return 0;
}