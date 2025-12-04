#include <bits/stdc++.h>
using namespace std;

int main() {

    long long ans = 0;
    while (true) {
        string s;
        cin >> s;

        if (s == "E") {
            break;
        }

        string str = "";
        for (int i = 0; i < s.size(); ++i) {
            int d = s[i] - '0';

            while (!str.empty() && str.back() - '0' < d && str.size() + (s.size() - i) > 12) {
                str.pop_back();
            }

            if (str.size() < 12) {
                str += char('0' + d);
            }
        }

        ans += stoll(str);
    }

    cout << ans;
}
