#include <bits/stdc++.h>
using namespace std;

int main() {

    int ans = 0;
    while (true) {
        string s;
        cin >> s;
        if (s == "E") {
            break;
        }

        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 1; j < s.length(); ++j) {
                int tens = s[i] - '0';
                int ones = s[j] - '0';
                int num = tens * 10 + ones;
                cnt = max(cnt, num);
            }
        }

        ans += cnt;
    }

    cout << ans;
}
