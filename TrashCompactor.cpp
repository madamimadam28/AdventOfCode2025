#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<long long>> nums;

    while (true) {
        string s;
        getline(cin, s);

        if (s == "E") break;

        stringstream ss(s);
        vector<long long> v;
        long long x;
        while (ss >> x) {
            v.push_back(x);
        }

        nums.push_back(v);
    }

    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<char> operations;
    char x;
    while (ss >> x) {
        operations.push_back(x);
    }

    long long ans = 0;
    for (int i = 0; i < nums[0].size(); ++i) {

        bool mul = false;
        long long sol = 0;
        if (operations[i] == '*') {
            mul = true;
            sol = 1;
        }

        for (int j = 0; j < nums.size(); ++j) {
            if (mul) {
                sol *= nums[j][i]; 
            }
            else {
                sol += nums[j][i];
            }
        }
        ans += sol;
    }
    cout << ans;
}