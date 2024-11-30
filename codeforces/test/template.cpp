#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;
vector<vector<char>> grid;
vector<vector<int>> dp;
unordered_map<char, pair<int, int>> dirs {{'U', { -1, 0}}, {'L', {0, -1}}, {'D', {1, 0}}, {'R', {0, 1}}};
vector<vector<int>> seen;

int dfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return 0;
    }

    if (dp[i][j])
    {
        return dp[i][j];
    }
    if (seen[i][j])
    {
        return dp[i][j] = 1;
    }
    seen[i][j] = 1;

    if (grid[i][j] == '?')
    {
        int res = 0;
        for (auto& [x, y] : dirs)
        {
            auto& [dr, dc] = y;
            res = max(res, dfs(i + dr, j + dc));
        }
        return dp[i][j] = res;
    }
    else
    {
        auto& [dr, dc] = dirs[grid[i][j]];
        return dp[i][j] = dfs(i + dr, j + dc);
    }
}

void solve()
{
    cin >> n >> m;
    grid = vector<vector<char>>(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    if (n == 1 && m == 1)
    {
        cout << 0 << '\n';
        return;
    }
    dp = vector<vector<int>>(n, vector<int>(m, 0));
    seen = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '?')
            {
                if ((i - 1 >= 0 && grid[i - 1][j] == 'D') || (i + 1 < n && grid[i + 1][j] == 'U') || (j - 1 >= 0 && grid[i][j - 1] == 'R') || (j + 1 < m && grid[i][j + 1] == 'L'))
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int ok = 0;
                    for (auto& [x, y] : dirs)
                    {
                        auto& [dr, dc] = y;
                        if (0 <= i + dr && i + dr < n && 0 <= j + dc && j + dc < m && grid[i + dr][j + dc] == '?')
                        {
                            ok = 1;
                        }
                    }
                    dp[i][j] = ok;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] != '?')
                dfs(i, j);
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dp[i][j])
            {
                ++res;
            }
        }
    }
    cout << res << '\n';
}

signed main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
