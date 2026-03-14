#include <iostream>

using namespace std;

#define up '('
#define down ')'

int main() {

    string input;
    int floor = 0;

    cout << "Enter Santa's directions: ";
    cin >> input;

    for(char dir : input) {
        if(dir == up) {
            floor++;
        } else {
            floor--;
        }
    }

    cout << "Santa Ends up on floor: " << floor << endl;

    return 0;
}