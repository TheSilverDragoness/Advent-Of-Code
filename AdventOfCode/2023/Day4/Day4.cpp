#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

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
	std::map<int, int> cardtracker;
	bool winset = true;
	int winnum = 0;
	int cardnum = 0;
	int total = 0;
	int copies = 0;

	if (input.is_open())
	{
		while (getline(input, str))
		{
			cardnum++;
			cardtracker[cardnum] = 1;
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

			copies = cardtracker.find(cardnum)->second;
			for (int a = cardnum; a < cardnum + winnum; a++)
			{
				if (a < cardtracker.size())
					cardtracker.find(a)->second += copies;
			}

		}

		for (int b = 0; b < cardnum; b++)
		{
			auto it = cardtracker.find(b);
			if (it != cardtracker.end())
			{
				total += cardtracker.find(b)->second;
			}
		}


		std::cout << "total: " << total << std::endl;
	}
	input.close();
}

int main()
{
	part2();
	return 0;
}