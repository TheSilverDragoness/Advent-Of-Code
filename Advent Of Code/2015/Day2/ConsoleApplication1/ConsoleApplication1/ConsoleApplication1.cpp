#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void part1()
{
    int area = 0;

    std::ifstream input{ "input.txt" };
    std::string file_line;

    while (getline(input, file_line))
    {
        int l, w, h;

        std::stringstream ss(file_line);
        char x;

        ss >> l >> x >> w >> x >> h;

        int a = 0, b = 0;

        if (l <= w && l <= h)
        {
            a = l;
            
            if (w <= h)
            {
                b = w;
            }
            else
            {
                b = h;
            }
        }
        else if (w <= l && w <= h)
        {
            a = w;

            if (l <= h)
            {
                b = l;
            }
            else
            {
                b = h;
            }
        }
        else if (h <= l && h <= w)
        {
            a = h;

            if (l <= w)
            {
                b = l;
            }
            else
            {
                b = w;
            }
        }

        area += +2 * l * w + 2 * w * h + 2 * l * h + a * b;
    }
    std::cout << "total area of paper required : " << area << std::endl;
}

void part2()
{
    int length = 0;

    std::ifstream input{ "input.txt" };
    std::string file_line;

    while (getline(input, file_line))
    {
        int l, w, h;

        std::stringstream ss(file_line);
        char x;

        ss >> l >> x >> w >> x >> h;

        int a = 0, b = 0;

        if (l <= w && l <= h)
        {
            a = l;

            if (w <= h)
            {
                b = w;
            }
            else
            {
                b = h;
            }
        }
        else if (w <= l && w <= h)
        {
            a = w;

            if (l <= h)
            {
                b = l;
            }
            else
            {
                b = h;
            }
        }
        else if (h <= l && h <= w)
        {
            a = h;

            if (l <= w)
            {
                b = l;
            }
            else
            {
                b = w;
            }
        }

        length += 2 * a + 2 * b + l * w * h;
    }

    std::cout << "total required length: " << length << std::endl;
}

int main()
{
    part2();
    return 0;
}