#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::ifstream input("input.txt");
std::string str;
std::string deliminator = " ";

bool check(size_t pos)
{
	return pos != std::string::npos;
}

std::vector<int> tokenise(const std::string& inputStr, const std::string& del)
{
	std::vector<int> tokens;

	size_t startPos;
	size_t endPos = 0;

	while (check(startPos = inputStr.find_first_not_of(del, endPos)))
	{
		endPos = inputStr.find_first_of(del, startPos);
		tokens.push_back(stoi(inputStr.substr(startPos, endPos - startPos)));
	}

	return tokens;
}

void Part1()
{
    std::vector<int> triangleEdges;

    int validTris = 0;

    while (getline(input, str))
    {
        triangleEdges = tokenise(str, deliminator);

        if ((triangleEdges[0] + triangleEdges[1]) <= triangleEdges[2])
            continue;
        if ((triangleEdges[0] + triangleEdges[2]) <= triangleEdges[1])
            continue;
        if ((triangleEdges[1] + triangleEdges[2]) <= triangleEdges[0])
            continue;

        validTris++;

        triangleEdges.clear();
    }

    std::cout << validTris;
}

void Part2()
{
    int validTris = 0;
    std::vector<int> triangleEdges;

    std::vector<std::vector<int>> triEdgeList;
    std::vector<int> triMegaList;

    while (getline(input, str))
    {
        triangleEdges = tokenise(str, deliminator);

        triEdgeList.push_back(triangleEdges);
    }

    int counter = 0;

    for (int i = 0; i < 3; i++)
    {
        for (auto v : triEdgeList)
        {
            triMegaList.push_back(v[i]);
        }
    }

    for (int i = 0; i < triMegaList.size(); i += 3)
    {
        int a = triMegaList[i];
        int b = triMegaList[i + 1];
        int c = triMegaList[i + 2];

        if (a + b > c && a + c > b && b + c > a)
        {
            validTris++;
        }
    }
    std::cout << validTris;
}

int main()
{
    if (!input.is_open())
    {
        std::cout << "Input is not open";
        return 1;
    }

    Part2();
    return 0;
}