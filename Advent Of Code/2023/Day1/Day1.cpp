#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <regex>
#include <algorithm>
using std::string;
using std::cout;
using std::endl;

void part1()
{
	std::ifstream input("input.txt");
	string str;

	int total = 0;

	while (getline(input, str))
	{
		char a;
		char b;

		for (int i = 0; i <= str.length(); i++)
		{
			if (std::isdigit(str[i]))
			{
				a = str[i];
				cout << "first num: " << a << endl;
			}
		}
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (std::isdigit(str[i]))
			{
				b = str[i];
				cout << "last num: " << b << endl;
			}
		}

		std::string number;
		number += b;
		number += a;
		cout << number << endl;
		int x = stoi(number);
		total += x;
	}

	cout << total;
}

void part2()
{
	std::ifstream input("input.txt");
	std::string str;

	int total = 0;

	string one("one");
	string two("two");
	string three("three");
	string four("four");
	string five("five");
	string six("six");
	string seven("seven");
	string eight("eight");
	string nine("nine");

	while (getline(input, str))
	{
		size_t start_pos1 = 0;
		while ((start_pos1 = str.find(one, start_pos1)) != std::string::npos)
		{
			str.replace(start_pos1, one.length(), "on1ne");
			start_pos1 += string("on1ne").length();
		}
		size_t start_pos2 = 0;
		while ((start_pos2 = str.find(two, start_pos2)) != std::string::npos)
		{
			str.replace(start_pos2, two.length(), "tw2wo");
			start_pos2 += string("tw2wo").length();
		}
		size_t start_pos3 = 0;
		while ((start_pos3 = str.find(three, start_pos3)) != std::string::npos)
		{
			str.replace(start_pos3, three.length(), "the3hree");
			start_pos3 += string("the3hree").length();
		}
		size_t start_pos4 = 0;
		while ((start_pos4 = str.find(four, start_pos4)) != std::string::npos)
		{
			str.replace(start_pos4, four.length(), "fou4our");
			start_pos4 += string("fou4our").length();
		}
		size_t start_pos5 = 0;
		while ((start_pos5 = str.find(five, start_pos5)) != std::string::npos)
		{
			str.replace(start_pos5, five.length(), "fiv5ive");
			start_pos5 += string("fiv5ive").length();
		}
		size_t start_pos6 = 0;
		while ((start_pos6 = str.find(six, start_pos6)) != std::string::npos)
		{
			str.replace(start_pos6, six.length(), "si6ix");
			start_pos6 += string("si6ix").length();
		}
		size_t start_pos7 = 0;
		while ((start_pos7 = str.find(seven, start_pos7)) != std::string::npos)
		{
			str.replace(start_pos7, seven.length(), "seve7even");
			start_pos7 += string("seve7even").length();
		}
		size_t start_pos8 = 0;
		while ((start_pos8 = str.find(eight, start_pos8)) != std::string::npos)
		{
			str.replace(start_pos8, eight.length(), "eigh8ight");
			start_pos8 += string("eigh8ight").length();
		}
		size_t start_pos9 = 0;
		while ((start_pos9 = str.find(nine, start_pos9)) != std::string::npos)
		{
			str.replace(start_pos9, nine.length(), "nin9ine");
			start_pos9 += string("nin9ine").length();
		}
		//cout << str << endl;

		char a;
		char b;

		for (int i = 0; i <= str.length(); i++)
		{
			if (std::isdigit(str[i]))
			{
				a = str[i];
				//cout << "first num: " << a << endl;
			}
		}
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (std::isdigit(str[i]))
			{
				b = str[i];
				//cout << "last num: " << b << endl;
			}
		}

		std::string number;
		number += b;
		number += a;
		//cout << number << endl;
		int x = stoi(number);
		total += x;
	}

	cout << total;
}

int main()
{
	part2();
	return 0;
}