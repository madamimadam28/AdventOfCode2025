#include <bits/stdc++.h>
using namespace std;

bool check(long long num) {
    string s = to_string(num);
    int len = s.size();
    if (len % 2 != 0) {
        return false;
    }

    string first = s.substr(0, len / 2);
    string second = s.substr(len / 2);
    return first == second;
}

int main() {
    string input = "69810572-69955342,3434061167-3434167492,76756725-76781020,49-147,"
                   "296131-386620,910523-946587,34308309-34358652,64542-127485,"
                   "640436-659023,25-45,35313993-35393518,753722181-753795479,1544-9792,"
                   "256-647,444628-483065,5863911-6054673,6969623908-6969778569,658-1220,"
                   "12631-63767,670238-830345,1-18,214165106-214245544,3309229-3355697";
    
    vector<pair<long long, long long>> ranges;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        size_t dash = token.find('-');
        long long start = stoll(token.substr(0, dash));
        long long end = stoll(token.substr(dash + 1));
        ranges.push_back({start, end});
    }

    long long sum = 0;
    for (auto &r : ranges) {
        for (long long i = r.first; i <= r.second; ++i) {
            if (check(i)) {
                sum += i;
            }
        }
    }

    cout << sum;
}
