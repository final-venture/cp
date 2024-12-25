#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
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

int getOutput(int y1, int x1, int y2, int x2, vector<vector<int>>& grid)
{
    return (grid[y2][x2] - grid[y1 - 1][x2] - grid[y2][x1 - 1] + grid[y1 - 1][x1 - 1]);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            char x;
            cin >> x;
            grid[i][j] = (x == '*');
            grid[i][j] += grid[i][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            grid[i][j] += grid[i - 1][j];
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    while (q--)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << getOutput(y1, x1, y2, x2, grid) << '\n';
    }
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}