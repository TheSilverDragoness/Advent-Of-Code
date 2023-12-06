#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void part1()
{
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
	std::cout << total;
}

void part2()
{
	std::pair<uint32_t, uint32_t> race{ 59688274, 543102016641022 };
	uint64_t total = 0;
	
	for (uint32_t i = 0; i < race.first; i++)
	{
		if (race.second < (race.first - i) * i)
			total++;
	}

	std::cout << total;
}

int main()
{
	part2();
	return 0;
}