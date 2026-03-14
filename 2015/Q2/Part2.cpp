// Question: https://adventofcode.com/2015/day/2

#include <fstream>
#include <iostream>

int main()
{
    std::ifstream file("input");

    // stores a single line
    std::string line;

    // Check for error reading file
    if (!file.is_open())
    {
        std::cerr << "Unable to read file!" << std::endl;
        return 1;
    }

    int total_ribbon = 0;

    while (getline(file, line))
    {
        line += '\0'; // add null string terminator to line
        int dim[3], pos = 0;
        std::string num = "";

        // extract the 3 dimentions of the box from input and save it to dim[3]
        for (char c : line)
        {
            if (c == 'x' || c == '\0')
            {
                dim[pos++] = std::stoi(num);
                num = "";
            }
            else
            {
                num += c;
            }
        }

        // Calculate length of ribbon required
        int volume = dim[0] * dim[1] * dim[2]; // for the bow

        int d1 = 2 * (dim[0] + dim[1]),
            d2 = 2 * (dim[1] + dim[2]),
            d3 = 2 * (dim[2] + dim[0]);

        // get the smallest perimeter side
        int small = d1 < d2 ? (d1 < d3 ? d1 : d3) : (d2 < d3 ? d2 : d3);

        total_ribbon += small + volume;
    }

    // print total required amount of paper
    std::cout << total_ribbon << std::endl;

    return 0;
}