#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void part1()
{
	std::ifstream input("input.txt");
	std::string str;
	std::vector<int> seeds;
	bool isseed = true;
	
	if (input.is_open())
	{
		while (getline(input, str)) 
		{
			std::istringstream iss(str);
			std::string token;
			
			while (iss >> token)
			{
				if (isdigit(token[0]) && isdigit(token.back()) && isseed)
				{
					seeds.push_back(stoi(token));
				}
			}
			isseed = false;
		}
		std::cout << "seeds: ";
		for (int i = 0; i < seeds.size(); i++)
		{
			if (i < seeds.size())
				std::cout << seeds[i];
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