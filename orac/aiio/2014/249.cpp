#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> grid(h + 2, vector<int>(w + 2));
    vector<vector<int>> pfx(h + 2, vector<int>(w + 2, 0));
    vector<vector<int>> dp_down(h + 2, vector<int>(w + 2, 0));
    vector<vector<int>> dp_up(h + 2, vector<int>(w + 2, 0));
    for (int i = h; i >= 1; --i)
    {
        for (int j = 1; j <= w; ++j)
        {
            cin >> grid[i][j];
        }
    }
    for (int j = 1; j <= w; ++j)
    {
        for (int i = 1; i <= h; ++i)
        {
            pfx[i][j] = pfx[i - 1][j] + grid[i][j];
        }
    }

    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            dp_down[i][j] = max({dp_down[i - 1][j - 1] + pfx[i - 1][j - 1], dp_down[i][j - 1] + pfx[i][j - 1]});
            dp_down[i][j] = max(dp_down[i][j], dp_down[i - 1][j]);
        }
    }
    for (int i = 1; i <= h; ++i)
    {
        for (int j = w; j >= 1; --j)
        {
            dp_up[i][j] = max({dp_up[i][j + 1] + pfx[i - 1][j + 1], dp_up[i - 1][j + 1] + pfx[i - 1][j + 1]});
            dp_up[i][j] = max(dp_up[i][j], dp_up[i - 1][j]);
        }
    }

    int ret = 0;
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            ret = max(ret, dp_up[i][j] + dp_down[i][j] + pfx[i][j]);
        }
    }
    // cout << '\n';
    cout << ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
