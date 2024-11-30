#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool check(size_t pos)
{
	return pos != std::string::npos;
}

std::vector<std::string> tokenise(const std::string& inputStr, const std::string& del)
{
	std::vector<std::string> tokens;

	size_t startPos;
	size_t endPos = 0;

	while (check(startPos = inputStr.find_first_not_of(del, endPos)))
	{
		endPos = inputStr.find_first_of(del, startPos);
		tokens.push_back(inputStr.substr(startPos, endPos - startPos));
	}

	return tokens;
}

int IncrementDirection(int currentDirection, char direction)
{
	int newDirection = currentDirection;
	if (direction == 'L')
	{
		newDirection--;

		if (newDirection < 0)
		{
			newDirection = 3;
		}
	}
	else if (direction == 'R')
	{
		newDirection++;

		if (newDirection > 3)
		{
			newDirection = 0;
		}
	}
	else
	{
		std::cout << "No Direction Specified";
	}
	
	return newDirection;
}

void part1()
{
	std::ifstream input("input.txt");
	std::string str;
	std::vector<std::string> directionVect;
	std::string deliminator = ", ";

	int xcoord = 0;
	int ycoord = 0;
	int direction = 0;
	

	if (input.is_open())
	{
		getline(input, str);
		directionVect = tokenise(str, deliminator);

		for (int i = 0; i < directionVect.size(); i++)
		{
			std::cout << directionVect[i] << '\n';

			char dir = directionVect[i][0];
			int steps = atoi(&directionVect[i][1]);
			direction = IncrementDirection(direction, dir);

			switch (direction)
			{
			case 0:
				xcoord += steps;
				break;
			case 1:
				ycoord += steps;
				break;
			case 2:
				xcoord -= steps;
				break;
			case 3:
				ycoord -= steps;
				break;
			default:
				std::cout << "no direction" << '\n';
				break;
			}
		}

		std::cout << abs(xcoord) + abs(ycoord);
	}
}

void part2()
{
	std::ifstream input("input.txt");
	std::string str;
	std::vector<std::string> directionVect;
	std::vector<std::pair<int, int>> locationVect;
	std::string deliminator = ", ";

	int xcoord = 0;
	int ycoord = 0;
	int direction = 0;

	if (input.is_open())
	{
		if (input.is_open())
		{
			getline(input, str);
			directionVect = tokenise(str, deliminator);

			for (int i = 0; i < directionVect.size(); i++)
			{
				//std::cout << directionVect[i] << '\n';

				char dir = directionVect[i][0];
				int steps = atoi(&directionVect[i][1]);
				direction = IncrementDirection(direction, dir);

				for (int i = 0; i < steps; i++)
				{
					switch (direction)
					{
					case 0:
						xcoord++;
						break;
					case 1:
						ycoord++;
						break;
					case 2:
						xcoord--;
						break;
					case 3:
						ycoord--;
						break;
					default:
						std::cout << "no direction" << '\n';
						break;
					}

					std::pair<int, int> currentCoord(xcoord, ycoord);

					if (std::find(locationVect.begin(), locationVect.end(), currentCoord) != locationVect.end())
					{
						std::cout << "Easter Bunny HQ is at: " << abs(currentCoord.first) + abs(currentCoord.second) << '\n';
						return;
					}
					else
					{
						locationVect.push_back(currentCoord);
						//std::cout << "location not found, pushing back: " << currentCoord.first << ", " << currentCoord.second << '\n';
					}
				}
			}
		}
	}
}

int main()
{
	part2();
	return 0;
}