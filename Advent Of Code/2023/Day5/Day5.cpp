#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cinttypes>

void part1()
{
	std::ifstream input("input.txt");
	std::string str;
	std::vector<uint32_t> seedlist;
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
					std::cout << token << std::endl;
					seedlist.push_back(stoull(token));
				}
				if (token == "map:")
				{

				}
			}
			isseed = false;
		}
		std::cout << "seeds: ";
		for (int i = 0; i < seedlist.size(); i++)
		{
			std::cout << seedlist[i] << " ";
		}
	}
	input.close();
}

void part2()
{
	std::ifstream input("input.txt");
	std::string str;

	if (input.is_open())
	{

	}
	input.close();
}

int main()
{
	part1();
	return 0;
}