#include <iostream>

using namespace std;

#define up '('
#define down ')'
#define target_floor -1

int main() {

    string input;
    int floor = 0, position = 1;

    cout << "Enter Santa's directions: ";
    cin >> input;

    for(char dir : input) {
        if(dir == up) {
            floor++;
        } else {
            floor--;
        }

        if(floor == target_floor) {
            cout << "Santa arrivers on floor -1 at position " << position << endl;
            return 0;
        }

        position++;
    }

    return 0;
}