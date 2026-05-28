#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const vector<pair<int, int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

inline bool valid(int r, int c) {
    return (r >= 0 && r < 8 && c >= 0 && c < 8);
}

void solve()
{
    vector<vector<char>> grid(8, vector<char>(8));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> grid[i][j];
        }
    }
    string s;
    cin >> s;
    int sz = s.size();
    int currR = 7, currC = 0;
    int currDirIdx = 0;
    for (int i = 0; i < sz; ++i) {
        auto [dr, dc] = dirs[currDirIdx];
        if (s[i] == 'F') {
            int nr = currR + dr, nc = currC + dc;
            if (valid(nr, nc) && grid[nr][nc] != 'C' && grid[nr][nc] != 'I') {
                currR = nr;
                currC = nc;
            }
            else {
                cout << "Bug!" << '\n';
                return;
            }
        }
        else if (s[i] == 'R') {
            currDirIdx++;
            currDirIdx %= 4;
        }
        else if (s[i] == 'L') {
            currDirIdx = (currDirIdx + 4 - 1) % 4;
        }
        else if (s[i] == 'X') {
            int nr = currR + dr, nc = currC + dc;
            if (valid(nr, nc) && grid[nr][nc] == 'I') {
                grid[nr][nc] = '.';
            }
            else {
                cout << "Bug!" << '\n';
                return;
            }
        }
    }

    if (grid[currR][currC] == 'D') {
        cout << "Diamond!" << '\n';
    }
    else {
        cout << "Bug!" << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
