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
    vector<vector<int>> seen(n, vector<int>(m, 0));
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<char>> path(n, vector<char>(m, '#'));
    unordered_map<char, pair<int, int>> dirs {{'U', { -1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
    unordered_map<char, pair<int, int>> revDirs {{'D', { -1, 0}}, {'U', {1, 0}}, {'R', {0, -1}}, {'L', {0, 1}}};
    queue<pair<pair<int, int>, int>> q;
    pair<int, int> hloc;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                seen[i][j] = 1;
                hloc = {i, j};
            }
            if (grid[i][j] == 'M')
            {
                seen[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }
    int ok = 0;
    int endr;
    int endc;
    q.push({hloc, 1});
    while (!q.empty())
    {
        auto [p, human] = q.front();
        auto [r, c] = p;
        q.pop();
        if (human && (r == 0 || r == n - 1 || c == 0 || c == m - 1))
        {
            ok = 1;
            endr = r; endc = c;
            break;
        }
        for (auto [dir, p] : dirs)
        {
            // cout << dir << '\n';
            auto [dr, dc] = p;
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (!seen[nr][nc] && grid[nr][nc] != '#')
            {
                seen[nr][nc] = 1;
                q.push({{nr, nc}, human});
                if (human)
                {
                    path[nr][nc] = dir;
                }
            }
        }
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         cout << path[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    if (!ok)
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
        vector<char> ret;
        while (grid[endr][endc] != 'A')
        {
            char d = path[endr][endc];
            ret.pb(d);
            auto [dr, dc] = revDirs[d];
            endr += dr; endc += dc;
        }
        reverse(all(ret));
        cout << ret.size() << '\n';
        for (char c : ret) cout << c;
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
