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
vector<vector<int>> seen;
vector<pair<int, int>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int dfs(int r, int c)
{
    if (seen[r][c]) return 0;
    seen[r][c] = 1;
    if (grid[r][c] == '#') return 0;
    for (auto& [dr, dc] : dirs)
    {
        int nr = r + dr, nc = c + dc;
        if (nr < 0 || nr >= n || nc >= m || nc < 0) continue;
        dfs(nr, nc);
    }
    return 1;
}

void solve()
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    seen.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ret += dfs(i, j);
        }
    }
    cout << ret << '\n';
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
