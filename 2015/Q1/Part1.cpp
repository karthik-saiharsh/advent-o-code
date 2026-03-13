// Question: https://adventofcode.com/2015/day/1


#include <iostream>
#include <vector>

int main() {
    std::string directions;
    int floor = 0;
    
    std::cout << "Enter Santa's Instructions: ";

    std::cin >> directions;

    for (char direction : directions) {
        if (direction == '(') floor++;
        else floor--;
    }

    std::cout << "Sants is on floor " << floor << std::endl;

    return 0;
}