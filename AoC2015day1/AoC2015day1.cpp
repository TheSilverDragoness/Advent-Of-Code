#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void part1() {
    std::ifstream input{ "input.txt" };
    std::string content((std::istreambuf_iterator<char>(input)),
        (std::istreambuf_iterator<char>()));

    int a = std::count(content.begin(), content.end(), '(');
    int b = std::count(content.begin(), content.end(), ')');

    std::cout << a - b;
}

void part2() {
    std::ifstream input{ "input.txt" };
    std::string content((std::istreambuf_iterator<char>(input)),
        (std::istreambuf_iterator<char>()));

    int pos = 0;
    int a = 0;
    int b = 0;

    for (int i = 0; i < content.length(); i++) {
        pos++;
        if (content[i] == '(')
            a++;
        if (content[i] == ')')
            b++;

        if (a - b < 0) {
            std::cout << pos;
            break;
        }
    }
}

int main() {
    part2();
    return 0;
}