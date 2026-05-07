#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9


int n;

void solve()
{
    cin >> n;
    vector<vector<int>> grid(5, vector<int>(n + 2, 0));
    int start = max(1LL, (n - 3) * n + 1);
    for (int i = 1; i < min(n + 1, 4LL); ++i) {
        for (int j = 1; j < n + 1; ++j) {
            grid[i][j] = start;
            ++start;
        }
    }
    
    int ret = 0;
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            // int cand = grid[i][j];
            ret = max(ret, grid[i][j] + grid[i - 1][j] + grid[i][j - 1] + grid[i + 1][j] + grid[i][j + 1]);
        }
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}