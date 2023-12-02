#include <iostream>
#include <fstream>
#include <string>

void part1()
{
	std::ifstream input("input.txt");
	std::string str;
	int x = 0, y = 0;
	char dir = 'u';

	if (input.is_open())
	{
		std::getline(input, str);

		for (int i = 0; i < str.length(); i++)
		{
			if (isalpha(str[i]))
			{
				if (str[i] == 'L')
				{
					i += 1;
					switch (dir)
					{
					case 'u':
						y -= int(str[i]);
						dir = 'l';
						break;
					case 'l':
						x -= int(str[i]);
						dir = 'd';
						break;
					case 'd':
						y += int(str[i]);
						dir = 'r';
						break;
					case 'r':
						x += int(str[i]);
						dir = 'u';
						break;
					}
				}
				else if (str[i] == 'R')
				{
					i += 1;
					switch (dir)
					{
					case 'u':
						x += int(str[i]);
						dir = 'r';
						break;
					case 'l':
						y -= int(str[i]);
						dir = 'u';
						break;
					case 'd':
						x -= int(str[i]);
						dir = 'l';
						break;
					case 'r':
						y += int(str[i]);
						dir = 'd';
						break;
					}
				}
				else
				{
					std::cout << "no direction specified" << std::endl;
				}
			}
		}
		std::cout << "answer: " << abs(x + y);
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