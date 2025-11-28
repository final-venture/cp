#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

unordered_map<char, pair<int, int>> dirs{{'L', {0, -1}}, {'R', {0, 1}}, {'D', {1, 0}}, {'U', {-1, 0}}};

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> row_sum(n + 1, 0);
    vector<int> col_sum(m + 1, 0);
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> grid[i][j];
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
        }
    }
    vector<vector<int>> ret(grid.begin(), grid.end());
    int cr = 1, cc = 1;
    for (char c : s)
    {
        auto [dr, dc] = dirs[c];
        if (c == 'D')
        {
            ret[cr][cc] = -(row_sum[cr]);
            col_sum[cc] += ret[cr][cc];
        }
        else if (c == 'R')
        {
            ret[cr][cc] = -(col_sum[cc]);
            row_sum[cr] += ret[cr][cc];
        }
        else
        {
            n = 0 / 0;
        }
        cr += dr;
        cc += dc;
    }
    ret[cr][cc] = -(row_sum[cr]);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }
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
