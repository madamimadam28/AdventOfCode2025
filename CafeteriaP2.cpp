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

    sort(ranges.begin(), ranges.end());

    vector<pair<long long, long long>> merged;

    for (auto range : ranges) {
        if (merged.empty() || range.first > merged.back().second + 1) {
            merged.push_back(range);
        }
         else {
            merged.back().second = max(merged.back().second, range.second);
        }
    }

    long long ans = 0;
    for (auto merge : merged) {
        ans += (merge.second - merge.first + 1);
    }

    cout << ans;
}