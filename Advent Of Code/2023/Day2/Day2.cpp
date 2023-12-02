#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

void part1()
{
	std::ifstream input("input.txt");
	std::string str;
	std::vector<int> vect;

	std::map<std::string, int> mp;

	mp["red"] = 0;
	mp["green"] = 1;
	mp["blue"] = 2;

	std::map<std::string, int>::iterator it;

	int gameval = 0, total = 0, cube = 0;

	if (input.is_open())
	{
		while (getline(input, str))
		{
			vect.clear();
			bool firstdig = true;
			std::istringstream iss(str);
			while (iss)
			{
				std::string word;
				iss >> word;
				//std::cout << word << std::endl;
				
				if (std::isdigit(word[0]))
				{
					int x = 0;
					x = std::stoi(word);
					if (firstdig)
					{
						gameval = x;
						firstdig = false;
						//std::cout << "x = " << x << std::endl;
					}
					else if (!firstdig)
					{
						iss >> word;
						word.erase(std::remove_if(word.begin(), word.end(), [](auto const& c) -> bool { return !std::isalnum(c); }), word.end());
						int col;
						it = mp.find(word);
						if (it != mp.end())
						{
							col = it->second;
							switch (col)
							{
							case 0:
								if (x <= 12)
								{
									vect.push_back(1);
									std::cout << "red" << std::endl;
								}
								else
								{
									vect.push_back(0);
								}
								break;
							case 1:
								if (x <= 13)
								{
									vect.push_back(1);
									std::cout << "green" << std::endl;
								}
								else
								{
									vect.push_back(0);
								}
								break;
							case 2:
								if (x <= 14)
								{
									vect.push_back(1);
									std::cout << "blue" << std::endl;
								}
								else
								{
									vect.push_back(0);
								}
								break;
							}
						}
					}
					else
					{
						std::cout << "error with values" << std::endl;
					}
				}
			}
			if (std::all_of(vect.begin(), vect.end(), [](int k) { return k == 1; }))
			{
				std::cout << gameval << std::endl;
				total += gameval;
			}
				
		}
		std::cout << "total value = " << total;
	}
}

void part2()
{
	std::ifstream input("input.txt");
	std::string str;
	std::vector<int> vectRed;
	std::vector<int> vectGreen;
	std::vector<int> vectBlue;

	std::map<std::string, int> mp;

	mp["red"] = 0;
	mp["green"] = 1;
	mp["blue"] = 2;

	std::map<std::string, int>::iterator it;

	int gameval = 0, total = 0, cube = 0;

	if (input.is_open())
	{
		while (getline(input, str))
		{
			int r = 0, g = 0, b = 0;
			vectRed.clear();
			vectGreen.clear();
			vectBlue.clear();

			bool firstdig = true;
			std::istringstream iss(str);
			while (iss)
			{
				std::string word;
				iss >> word;
				//std::cout << word << std::endl;

				if (std::isdigit(word[0]))
				{
					int x = 0;
					x = std::stoi(word);
					if (firstdig)
					{
						firstdig = false;
					}
					else if (!firstdig)
					{
						iss >> word;
						std::cout << word << std::endl;
						word.erase(std::remove_if(word.begin(), word.end(), [](auto const& c) -> bool { return !std::isalnum(c); }), word.end());
						std::cout << word << std::endl;
						int col;
						it = mp.find(word);
						if (it != mp.end())
						{
							col = it->second;
							switch (col)
							{
							case 0:
								vectRed.push_back(x);
								std::cout << "red: " << x << std::endl;
								break;
							case 1:
								vectGreen.push_back(x);
								std::cout << "green: " << x << std::endl;
								break;
							case 2:
								vectBlue.push_back(x);
								std::cout << "blue: " << x << std::endl;
								break;
							}
						}
					}
					else
					{
						std::cout << "error with values" << std::endl;
					}
				}
			}
			r = * std::max_element(vectRed.begin(), vectRed.end());
			g = * std::max_element(vectGreen.begin(), vectGreen.end());
			b = * std::max_element(vectBlue.begin(), vectBlue.end());
			std::cout << "red: " << r << " green: " << g << " blue: " << b << std::endl;
			total += r * g * b;
		}
		std::cout << "total value = " << total;
	}
}

int main()
{
	part2();
	std::cout << "part1: " << 110-9 << "part2: " << 197 - 112 << std::endl;
	return 0;
}