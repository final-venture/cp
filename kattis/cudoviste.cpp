#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int R, C;
    cin >> R >> C;
    vector<vector<char>> grid(R, vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<int> ret(5, 0);
    for (int i = 1; i < R; ++i) {
        for (int j = 1; j < C; ++j) {
            if ((grid[i - 1][j - 1] == '#') || (grid[i - 1][j] == '#') || (grid[i][j - 1] == '#') || (grid[i][j] == '#')) {
                continue;
            }
            int sq = (grid[i - 1][j - 1] == 'X') + (grid[i - 1][j] == 'X') + (grid[i][j - 1] == 'X') + (grid[i][j] == 'X');
            ret[sq]++;
        }
    }
    for (auto x : ret) {
        cout << x << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
