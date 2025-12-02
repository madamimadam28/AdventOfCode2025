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
            for (int i = 1; i <= value; i++) {
                dial = (dial - 1 + 100) % 100;
                if (dial == 0) {
                    passcode++;
                }
            }
        }
        else if (command == 'R') {
            for (int i = 1; i <= value; i++) {
                dial = (dial + 1) % 100;
                if (dial == 0) {
                    passcode++;
                }
            }
        }
    }
    cout << passcode << endl;
}