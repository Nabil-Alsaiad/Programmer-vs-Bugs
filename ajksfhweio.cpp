//direction of player up and down movement
#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char input;
    
    cout << "Enter a direction (u, d, r, l) =>";
    cin >> input;

    if (input == 'u' || input == 'd' || input == 'l' || input == 'r') {
        cout << "You entered " << input << "." << endl;
    } else {
        cout << "Error: Input must be u, d, l, or r." << endl;
    }
}