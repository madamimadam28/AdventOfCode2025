#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<string>> nums;
    vector<string> lines;

    // Read all lines until "E"
    while (true) {
        string s;
        getline(cin, s);
        if (s == "E") break;
        lines.push_back(s);
    }

    // Split each line into columns (numbers)
    for (auto &line : lines) {
        line += ' '; // add space at end to handle last number
        string curr = "";
        bool found_num = false;
        vector<string> row;
        for (char ch : line) {
            if (ch != ' ') {
                curr += ch;
                found_num = true;
            } else if (found_num) {
                row.push_back(curr);
                curr = "";
                found_num = false;
            }
        }
        nums.push_back(row);
    }

    // Read operators
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<char> operations;
    char x;
    while (ss >> x) operations.push_back(x);

    long long grand_total = 0;

    int n_cols = nums[0].size();

    // Process each column
    for (int i = 0; i < n_cols; ++i) {
        vector<string> col_strings;
        size_t max_len = 0;

        // Collect the strings for this column
        for (int r = 0; r < nums.size(); ++r) {
            string str = nums[r][i];
            max_len = max(max_len, str.size());
            col_strings.push_back(str);
        }

        // Pad strings with spaces at the front so all have same length
        for (auto &str : col_strings) {
            while (str.size() < max_len) str = " " + str;
        }

        // Read digits bottom-to-top, right-to-left
        vector<long long> vals;
        for (int pos = max_len - 1; pos >= 0; --pos) {
            long long val = 0;
            long long place = 1;
            bool all_spaces = true;
            for (int r = 0; r < col_strings.size(); ++r) {
                if (col_strings[r][pos] != ' ') {
                    all_spaces = false;
                    val += (col_strings[r][pos] - '0') * place;
                    place *= 10;
                }
            }
            if (!all_spaces) vals.push_back(val);
        }

        // Apply operator
        long long sol = (operations[i] == '*') ? 1 : 0;
        for (auto v : vals) {
            if (operations[i] == '*') sol *= v;
            else sol += v;
        }

        grand_total += sol;
    }

    cout << grand_total << endl;
}
