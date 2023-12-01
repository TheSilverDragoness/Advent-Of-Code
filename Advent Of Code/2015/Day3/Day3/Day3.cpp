#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

void part1() 
{
	std::ifstream input{ "input.txt" };

	int x = 0;
	int y = 0;

	int houses = 1;

	std::vector <std::pair<int, int>> coordinates;
	std::pair<int, int> pos(x, y);
	coordinates.push_back(pos);

	if (input.is_open())
	{
		std::string content((std::istreambuf_iterator<char>(input)),
			(std::istreambuf_iterator<char>()));

		//std::cout << content;

		for (int i = 0; i < content.length(); i++)
		{
			switch (content[i])
			{
			case '^':
				y += 1;
				break;
			case 'v':
				y -= 1;
				break;
			case '>':
				x += 1;
				break;
			case '<':
				x -= 1;
				break;
			default:
				std::cout << "error with the switch" << std::endl;
				break;
			}
			//std::cout << "Santa's Coordinates: x =  " << x << " y = " << y << std::endl;

			std::pair<int, int> pos(x, y);

			if (!std::count(coordinates.begin(), coordinates.end(), pos))
			{
				houses++;
				coordinates.push_back(pos);
			}
		}

		std::cout << " unique houses visited: " << houses << std::endl;
	}
	else
	{
		std::cout << "file didnt open" << std::endl;
	}
}

void part2()
{
	std::ifstream input{ "input.txt" };

	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	int houses = 1;

	std::vector <std::pair<int, int>> coordinates;
	std::pair<int, int> pos(x1, y1);
	coordinates.push_back(pos);

	if (input.is_open())
	{
		std::string content((std::istreambuf_iterator<char>(input)),
			(std::istreambuf_iterator<char>()));

		//std::cout << content;

		bool fleshsanta = true;

		for (int i = 0; i < content.length(); i++)
		{
			if (fleshsanta)
			{
				std::cout << "FleshSanta" << std::endl;
				switch (content[i])
				{
				case '^':
					y1 += 1;
					break;
				case 'v':
					y1 -= 1;
					break;
				case '>':
					x1 += 1;
					break;
				case '<':
					x1 -= 1;
					break;
				default:
					std::cout << "error with the switch" << std::endl;
					break;
				}
				//std::cout << "Santa's Coordinates: x =  " << x << " y = " << y << std::endl;

				std::pair<int, int> pos(x1, y1);

				if (!std::count(coordinates.begin(), coordinates.end(), pos))
				{
					houses++;
					coordinates.push_back(pos);
				}
				fleshsanta = false;
			}
			else if (!fleshsanta)
			{
				std::cout << "RoboSanta" << std::endl;
				switch (content[i])
				{
				case '^':
					y2 += 1;
					break;
				case 'v':
					y2 -= 1;
					break;
				case '>':
					x2 += 1;
					break;
				case '<':
					x2 -= 1;
					break;
				default:
					std::cout << "error with the switch" << std::endl;
					break;
				}
				//std::cout << "Santa's Coordinates: x =  " << x << " y = " << y << std::endl;

				std::pair<int, int> pos(x2, y2);

				if (!std::count(coordinates.begin(), coordinates.end(), pos))
				{
					houses++;
					coordinates.push_back(pos);
				}
				fleshsanta = true;
			}
			else
			{
				std::cout << "youve fucked it" << std::endl;
			}
		}

		std::cout << " unique houses visited: " << houses << std::endl;
	}
	else
	{
		std::cout << "file didnt open" << std::endl;
	}
}

int main()
{
	part2();
	return 0;
}