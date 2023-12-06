#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cinttypes>
#include <map>
#include <algorithm>

void part1()
{
	std::ifstream input("input.txt");
	std::string str;
	std::vector<uint32_t> seedlist;
	bool isseed = true;
	int maptype = 0;
	std::map<std::pair<uint32_t, uint32_t>, uint32_t> map1;
	std::map<std::pair<uint32_t, uint32_t>, uint32_t> map2;
	std::map<std::pair<uint32_t, uint32_t>, uint32_t> map3;
	std::map<std::pair<uint32_t, uint32_t>, uint32_t> map4;
	std::map<std::pair<uint32_t, uint32_t>, uint32_t> map5;
	std::map<std::pair<uint32_t, uint32_t>, uint32_t> map6;
	std::map<std::pair<uint32_t, uint32_t>, uint32_t> map7;
	std::vector<std::pair<uint32_t, uint32_t>> vec1;
	std::vector<std::pair<uint32_t, uint32_t>> vec2;
	std::vector<std::pair<uint32_t, uint32_t>> vec3;
	std::vector<std::pair<uint32_t, uint32_t>> vec4;
	std::vector<std::pair<uint32_t, uint32_t>> vec5;
	std::vector<std::pair<uint32_t, uint32_t>> vec6;
	std::vector<std::pair<uint32_t, uint32_t>> vec7;

	std::vector<uint32_t> mappedlist1;
	std::vector<uint32_t> mappedlist2;
	std::vector<uint32_t> mappedlist3;
	std::vector<uint32_t> mappedlist4;
	std::vector<uint32_t> mappedlist5;
	std::vector<uint32_t> mappedlist6;
	std::vector<uint32_t> mappedlist7;

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
					seedlist.push_back(stoull(token));
				}
				if (token == "map:")
				{
					maptype++;
				}
			}
			if (!isseed && isdigit(str[0]))
			{
				std::istringstream istr(str);
				uint32_t a = 0, b = 0, c = 0;
				switch (maptype)
				{
				case 1:
					istr >> a >> b >> c;
					map1.insert({ {b, c}, a });
					vec1.push_back({ b, c });
					break;
				case 2:
					istr >> a >> b >> c;
					map2.insert({ {b, c}, a });
					vec2.push_back({ b, c });
					break;
				case 3:
					istr >> a >> b >> c;
					map3.insert({ {b, c}, a });
					vec3.push_back({ b, c });
					break;
				case 4:
					istr >> a >> b >> c;
					map4.insert({ {b, c}, a });
					vec4.push_back({ b, c });
					break;
				case 5:
					istr >> a >> b >> c;
					map5.insert({ {b, c}, a });
					vec5.push_back({ b, c });
					break;
				case 6:
					istr >> a >> b >> c;
					map6.insert({ {b, c}, a });
					vec6.push_back({ b, c });
					break;
				case 7:
					istr >> a >> b >> c;
					map7.insert({ {b, c}, a });
					vec7.push_back({ b, c });
					break;
				default:
					std::cout << "error with the switch" << std::endl;
					break;
				}
			}
			isseed = false;
		}
		for (int i = 0; i < seedlist.size(); i++)
		{
			for (int a = 0; a < vec1.size(); a++)
			{
				if (seedlist[i] < vec1[a].first + vec1[a].second - 1 && seedlist[i] > vec1[a].first)
				{
					mappedlist1.push_back(map1.find(vec1[a])->second + vec1[a].second - 1);
					std::cout << "conversion 1" << std::endl;
					break;
				}
				else if (a = vec1.size() && !(seedlist[i] < vec1[a].first + vec1[a].second - 1 && seedlist[i] > vec1[a].first))
				{
					mappedlist1.push_back(seedlist[i]);
				}
			}
		}
		for (int i = 0; i < mappedlist1.size(); i++)
		{
			for (int a = 0; a < vec2.size(); a++)
			{
				if (mappedlist1[i] < vec2[a].first + vec2[a].second - 1 && mappedlist1[i] > vec2[a].first)
				{
					mappedlist2.push_back(map2.find(vec2[a])->second + vec2[a].second - 1);
					std::cout << "conversion 2" << std::endl;
					break;
				}
				else if (a = vec2.size() && !(mappedlist1[i] < vec2[a].first + vec2[a].second - 1 && mappedlist1[i] > vec2[a].first))
				{
					mappedlist2.push_back(mappedlist1[i]);
				}
			}
		}
		for (int i = 0; i < mappedlist2.size(); i++)
		{
			for (int a = 0; a < vec3.size(); a++)
			{
				if (mappedlist2[i] < vec3[a].first + vec3[a].second - 1 && mappedlist2[i] > vec3[a].first)
				{
					mappedlist3.push_back(map3.find(vec3[a])->second + vec3[a].second - 1);
					std::cout << "conversion 3" << std::endl;
					break;
				}
				else if (a = vec3.size() && !(mappedlist2[i] < vec3[a].first + vec3[a].second - 1 && mappedlist2[i] > vec3[a].first))
				{
					mappedlist3.push_back(mappedlist2[i]);
				}
			}
		}
		for (int i = 0; i < mappedlist3.size(); i++)
		{
			for (int a = 0; a < vec4.size(); a++)
			{
				if (mappedlist3[i] < vec4[a].first + vec4[a].second - 1 && mappedlist3[i] > vec4[a].first)
				{
					mappedlist4.push_back(map4.find(vec4[a])->second + vec4[a].second - 1);
					std::cout << "conversion 4" << std::endl;
					break;
				}
				else if (a = vec4.size() && !(mappedlist3[i] < vec4[a].first + vec4[a].second - 1 && mappedlist3[i] > vec4[a].first))
				{
					mappedlist4.push_back(mappedlist3[i]);
				}
			}
		}
		for (int i = 0; i < mappedlist4.size(); i++)
		{
			for (int a = 0; a < vec5.size(); a++)
			{
				if (mappedlist4[i] < vec5[a].first + vec5[a].second - 1 && mappedlist4[i] > vec5[a].first)
				{
					mappedlist5.push_back(map5.find(vec5[a])->second + vec5[a].second - 1);
					std::cout << "conversion 5" << std::endl;
					break;
				}
				else if (a = vec5.size() && !(mappedlist4[i] < vec5[a].first + vec5[a].second - 1 && mappedlist4[i] > vec5[a].first))
				{
					mappedlist5.push_back(mappedlist4[i]);
				}
			}
		}
		for (int i = 0; i < mappedlist5.size(); i++)
		{
			for (int a = 0; a < vec6.size(); a++)
			{
				if (mappedlist5[i] < vec6[a].first + vec6[a].second - 1 && mappedlist5[i] > vec6[a].first)
				{
					mappedlist6.push_back(map6.find(vec6[a])->second + vec6[a].second - 1);
					std::cout << "conversion 6" << std::endl;
					break;
				}
				else if (a = vec6.size() && !(mappedlist5[i] < vec6[a].first + vec6[a].second - 1 && mappedlist5[i] > vec6[a].first))
				{
					mappedlist6.push_back(mappedlist5[i]);
				}
			}
		}
		for (int i = 0; i < mappedlist6.size(); i++)
		{
			for (int a = 0; a < vec7.size(); a++)
			{
				if (mappedlist6[i] < vec7[a].first + vec7[a].second - 1 && mappedlist6[i] > vec7[a].first)
				{
					mappedlist7.push_back(map7.find(vec7[a])->second + vec7[a].second - 1);
					std::cout << "conversion 7" << std::endl;
					break;
				}
				else if (a = vec7.size() && !(mappedlist6[i] < vec7[a].first + vec7[a].second - 1 && mappedlist6[i] > vec7[a].first))
				{
					mappedlist7.push_back(mappedlist6[i]);
				}
			}
		}
		std::cout << *std::min_element(mappedlist7.begin(), mappedlist7.end()) << std::endl;
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