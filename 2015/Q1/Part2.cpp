// Question: https://adventofcode.com/2015/day/1

#include <iostream>
#include <vector>

int main()
{
    std::string directions;
    int floor = 0, position = 1;

    std::cout << "Enter Santa's Instructions: ";

    std::cin >> directions;

    for (char direction : directions)
    {
        if (direction == '(')
            floor++;
        else
            floor--;

        if (floor == -1)
        {
            std::cout << "Sants reaches -1 on floor: " << position << std::endl;
            return 0;
        }

        position++;
    }

    return 0;
}