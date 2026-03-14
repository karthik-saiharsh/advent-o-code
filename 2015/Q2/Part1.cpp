// Question: https://adventofcode.com/2015/day/2

#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("input");

    // stores a single line
    std::string line;

    // Check for error reading file
    if(!file.is_open()) {
        std::cerr << "Unable to read file!" << std::endl;
        return 1;
    }

    int total_paper = 0;

    while(getline(file, line)) {
        line += '\0'; // add null string terminator to line
        int dim[3], pos=0;
        std::string num = "";

        // extract the 3 dimentions of the box from input and save it to dim[3]
        for(char c : line) {
            if(c == 'x' || c == '\0') {
                dim[pos++] = std::stoi(num);
                num = "";
            } else {
                num += c;
            }
        }

        int lw = dim[0]*dim[1];
        int wh = dim[1]*dim[2];
        int hl = dim[2]*dim[0];

        // total surface area
        int SA = 2 * (lw + wh + hl);
        
        // area of smallest side
        int small = lw < wh ? (lw < hl ? lw : hl) : (wh < hl ? wh : hl);

        // total area for current present
        total_paper += SA + small;
    }

    // print total required amount of paper
    std::cout << total_paper << std::endl;

    return 0;
}