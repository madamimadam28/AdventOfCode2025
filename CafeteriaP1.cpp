#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<long long, long long>> ranges;

    while (true) {
        string s;
        cin >> s;

        if (s == "E") {
            break;
        }

        long long l, r;
        char dash;
        stringstream ss(s);
        ss >> l >> dash >> r;

        ranges.push_back({l, r});
    }

    long long ans = 0;
    while (true) {
        long long index;
        cin >> index;

        if (index == -1) {
            break;
        }
        
        for (auto range : ranges) {
            if (index >= range.first && index <= range.second) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}