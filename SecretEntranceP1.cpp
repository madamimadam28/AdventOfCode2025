#include <bits/stdc++.h>
using namespace std;

int main() {
    string code;
    int dial = 50;
    int passcode = 0;
    while (true) {
        cin >> code;

        if (code == "E") {
            break;
        }

        char command = code[0];
        int value = stoi(code.substr(1));
        if (command == 'L') {
            dial -= value;
        }
        else if (command == 'R') {
            dial += value;
        }

        dial = (dial % 100 + 100) % 100;

        if (dial == 0) {
            passcode++;
        }
    }
    cout << passcode << endl;
}