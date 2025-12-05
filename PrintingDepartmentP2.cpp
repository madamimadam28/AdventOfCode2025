#include <bits/stdc++.h>
using namespace std;

int n = 0, m;
vector<vector<char>> grid;


bool check(int i, int j) {
    int cnt = 0;
    if (i - 1 >= 0 && j - 1 >= 0) {
        cnt += (grid[i - 1][j - 1] == '@');
    }
    if (i + 1 < n && j - 1 >= 0) {
        cnt += (grid[i + 1][j - 1] == '@');
    }
    if (i - 1 >= 0 && j + 1 < m) {
        cnt += (grid[i - 1][j + 1] == '@');
    }
    if (i + 1 < n && j + 1 < m) {
        cnt += (grid[i + 1][j + 1] == '@');
    }
    if (i - 1 >= 0) {
        cnt += (grid[i - 1][j] == '@');
    }
    if (j - 1 >= 0) {
        cnt += (grid[i][j - 1] == '@');
    }
    if (i + 1 < n) {
        cnt += (grid[i + 1][j] == '@');
    }
    if (j + 1 < m) {
        cnt += (grid[i][j + 1] == '@');
    }

    return cnt < 4;
}

int main() {
    string line;

    while (true) {
        cin >> line;
        if (line == "E") {
            break;
        }

        m = line.length();
        n++;

        vector<char> arr;
        for (auto c : line) {
            arr.push_back(c);
        }

        grid.push_back(arr);
    }
    ;
    int ans = 0;
    bool changed = true; 

    while (changed) {
        changed = false;

        vector<vector<char>> prev_grid = grid; 
        vector<vector<char>> next_grid = grid; 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '@' && check(i, j)) {
                    next_grid[i][j] = '.'; 
                    ans++;
                }
            }
        }

        grid = next_grid; 

        if (grid != prev_grid) {
            changed = true;
        }
    }

    cout << ans;
}