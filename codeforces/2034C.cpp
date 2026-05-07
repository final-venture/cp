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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> seen(n, vector<int>(m, 0));
    vector<vector<int>> dirs {{0, -1, 'R'}, {0, 1, 'L'}, {1, 0, 'U'}, { -1, 0, 'D'}};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        if (grid[i][0] == 'L') q.push({i, 0});
        if (grid[i][m - 1] == 'R') q.push({i, m - 1});
    }
    for (int j = 0; j < m; ++j)
    {
        if (grid[0][j] == 'U') q.push({0, j});
        if (grid[n - 1][j] == 'D') q.push({n - 1, j});
    }

    // cout << q.empty() << '\n';
    // while (!q.empty())
    // {
    //     auto& [x, y] = q.front();
    //     q.pop();
    //     cout << x << ' ' << y << '\n';
    // }

    while (!q.empty())
    {
        auto& [r, c] = q.front();
        q.pop();
        if (seen[r][c]) continue;
        seen[r][c] = 1;
        for (auto& x : dirs)
        {
            int nr = r + x[0]; int nc = c + x[1]; int match = x[2];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] == match)
            {
                q.push({nr, nc});
            }
        }
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         cout << seen[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            if (grid[r][c] == '?')
            {
                seen[r][c] = 1;
                for (auto& x : dirs)
                {
                    int nr = r + x[0]; int nc = c + x[1];
                    if (0 <= nr && nr < n && 0 <= nc && nc < m && !seen[nr][nc])
                    {
                        seen[r][c] = 0;
                        break;
                    }
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            res += !seen[i][j];
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
