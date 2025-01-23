#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define MOD 1000003

int rows, cols;
vector<vector<int>> grid;
vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
vector<vector<bool>> mins;
vector<vector<ll>> dp;

bool valid(int r, int c)
{
    return (0 <= r && r < rows && 0 <= c && c < cols);
}

ll dfs(int r, int c)
{
    if (mins[r][c])
    {
        return 1;
    }
    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }
    ll ret = 0;
    for (auto &[dr, dc] : dirs)
    {
        int nr = r + dr, nc = c + dc;
        if (valid(nr, nc) && grid[nr][nc] < grid[r][c])
        {
            ret += dfs(nr, nc);
            ret %= MOD;
        }
    }
    return dp[r][c] = ret;
}

void solve()
{
    cin >> rows >> cols;
    grid.resize(rows, vector<int>(cols));
    mins.resize(rows, vector<bool>(cols, false));
    dp.resize(rows, vector<ll>(cols, -1));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> grid[i][j];
        }
    }
    vector<pair<int, int>> st;
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            bool canBeMin = 1, canBeMax = 1;
            for (auto &[dr, dc] : dirs)
            {
                int nr = r + dr, nc = c + dc;
                if (valid(nr, nc))
                {
                    if (grid[nr][nc] > grid[r][c])
                    {
                        canBeMax = 0;
                    }
                    else if (grid[nr][nc] < grid[r][c])
                    {
                        canBeMin = 0;
                    }
                }
            }
            if (canBeMax)
            {
                st.push_back({r, c});
            }
            if (canBeMin)
            {
                mins[r][c] = true;
            }
        }
    }
    ll ret = 0;

    // for (int i = 0; i < rows; ++i)
    // {
    //     for (int j = 0; j < cols; ++j)
    //     {
    //         cout << mins[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (auto &[r, c] : st)
    {
        ret += dfs(r, c);
        ret %= MOD;
        // cout << r << ' ' << c << '\n';
    }
    cout << ret;
}

signed main()
{
#ifndef LOCAL
    freopen("birdin.txt", "r", stdin);
    freopen("birdout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
