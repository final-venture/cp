#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m + 1, vector<int>(n + 1));
    vector<vector<int>> pfx(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> grid[i][j];
            pfx[i][j] = grid[i][j];
            pfx[i][j] += pfx[i][j - 1];
            pfx[i][j] += pfx[i - 1][j];
            pfx[i][j] -= pfx[i - 1][j - 1];
        }
    }

    // for (int i = 1; i <= m; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         cout << pfx[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int cnt = 0;

    for (int sr = 1; sr <= m; ++sr)
    {
        for (int sc = 1; sc <= n; ++sc)
        {
            for (int er = sr; er <= m; ++er)
            {
                if (er - sr + 1 >= 13)
                    break;
                for (int ec = sc; ec <= n; ++ec)
                {
                    int summ = pfx[er][ec] - pfx[sr - 1][ec] - pfx[er][sc - 1] + pfx[sr - 1][sc - 1];
                    if (summ == 10)
                        ++cnt;
                    if (summ >= 10)
                        break;
                }
            }
        }
    }
    cout << cnt << '\n';
}

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}