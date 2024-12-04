#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "timer.h"

void part1()
{
	Timer timer;
	timer.Reset();
	std::vector<std::pair<int, int>> races;

	races.push_back({ 59, 543 });
	races.push_back({ 68, 1020 });
	races.push_back({ 82, 1664 });
	races.push_back({ 74, 1022 });

	int winperms = 0, total = 1;
	std::vector<int> waystowin;

	for (int i = 0; i < races.size(); i++)
	{
		winperms = 0;
		for (int a = 0; a < races[i].second; a++)
		{
			if (races[i].second < (races[i].first - a) * a)
			{
				winperms++;
			}
		}
		waystowin.push_back(winperms);
	}
	for (int k = 0; k < waystowin.size(); k++)
	{
		total *= waystowin[k];
	}
	float time = timer.Elapsed();
	std::cout << "part 1 answer: " << total << " Elapsed time (s): " << time << std::endl;
}

void part2()
{
	Timer timer;
	timer.Reset();
	std::pair<uint64_t, uint64_t> race{ 59688274, 543102016641022 };
	uint64_t total = 0;
	
	for (uint32_t i = 0; i < race.first; i++)
	{
		if (race.second < (race.first - i) * i)
			total++;
	}
	float time = timer.Elapsed();
	std::cout << "part 2 answer: " << total << " Elapsed time (s): " << time << std::endl;
}

int main()
{
	part1();
	part2();
	return 0;
}