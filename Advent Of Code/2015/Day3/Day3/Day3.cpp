#include <iostream>
#include <fstream>
#include <string>

void part1() 
{
	std::ifstream input{ "input.txt" };
	std::string file_line;

	if (input.is_open())
	{
		std::string content((std::istreambuf_iterator<char>(input)),
			(std::istreambuf_iterator<char>()));
	}
}

void part2()
{
	std::ifstream input{ "input.txt" };
	std::string file_line;
	if (input.is_open())
	{
		std::string content((std::istreambuf_iterator<char>(input)),
			(std::istreambuf_iterator<char>()));
	}
}

int main()
{
	part1();
	return 0;
}