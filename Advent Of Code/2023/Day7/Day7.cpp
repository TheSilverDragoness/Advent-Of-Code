#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void part1()
{
	std::ifstream input("input.txt");
	std::string str;

	std::vector<std::pair<std::string, int>> ALLCARDS;

	std::vector<std::pair<std::string, int>> FiveOfAKind;
	std::vector<std::pair<std::string, int>> FourOfAKind;
	std::vector<std::pair<std::string, int>> FullHouse;
	std::vector<std::pair<std::string, int>> ThreeOfAKind;
	std::vector<std::pair<std::string, int>> TwoPair;
	std::vector<std::pair<std::string, int>> OnePair;
	std::vector<std::pair<std::string, int>> HighCard;

	if (input.is_open())
	{
		while (getline(input, str))
		{
			std::istringstream iss(str);
			std::string hand;
			int bid;
			iss >> hand >> bid;
			ALLCARDS.push_back({ hand, bid });
		}
	}

	for (int i = 0; i < ALLCARDS.size(); i++)
	{
		for (int k = 0; k < ALLCARDS[i].first.length(); k++)
		{
			ALLCARDS[i].first[k]
		}
	}
}

void part2()
{

}

int main()
{
	part1();
	return 0;
}