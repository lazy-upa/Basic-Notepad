#include <iostream>
#include "file.h"
#include <string>

using namespace std;

int main() {
    string s;
    int o;
    file f;

    cout << "-----------------------------------------\n";
    cout << "\tWelcome to Basic Notepad\n";
    cout << "-----------------------------------------\n";

    while (true) {
        cout << "1 - Write a new File!\n";
        cout << "2 - Display saved content from the file!\n";
        cout << "3 - Edit a line from the file\n";
        cout << "4 - Exit!\n";

        cout << "\n\nWhat do you wanna do?\n";
        cin >> o;

        if (o == 4) {
            cout << "Thanks for using this program!\n";
            break;
        }

        f.optionFile(o);
        cout << "\n";
    }

    return 0;
}
