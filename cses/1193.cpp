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
pair<int, int> st;
vector<vector<char>> grid;
vector<vector<char>> path;
vector<char> ret;
vector<vector<int>> seen;
unordered_map<char, pair<int, int>> dirs {{'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
unordered_map<char, pair<int, int>> revDirs {{'R', {0, -1}}, {'L', {0, 1}}, {'D', {-1, 0}}, {'U', {1, 0}}};

// void dfs(int r, int c, char move)
// {
//     // cout << r << ' ' << c << endl;
//     if (grid[r][c] == 'B')
//     {
//         ok = 1;
//         revRet.pb(move);
//         return;
//     }
//     if (seen[r][c]) return;
//     seen[r][c] = 1;
//     if (grid[r][c] == '#') return;
//     for (auto [d, p] : dirs)
//     {
//         auto [dr, dc] = p;
//         int nr = r + dr, nc = c + dc;
//         if (nr < 0 || nr >= n || nc < 0 || nc >= m || ok) continue;
//         dfs(nr, nc, d);
//     }
//     if (ok && move != 'X')
//     {
//         revRet.pb(move);
//     }
// }

void solve()
{
    cin >> n >> m;
    seen.resize(n, vector<int>(m));
    grid.resize(n, vector<char>(m));
    path.resize(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                st = {i, j};
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({st.first, st.second});
    while (!q.empty())
    {   
        auto [r, c] = q.front();
        q.pop();
        if (grid[r][c] == 'B')
        {
            while (r != st.first || c != st.second)
            {
                ret.pb(path[r][c]);
                auto [dr, dc] = revDirs[path[r][c]];
                r += dr; c += dc;
            }
            break;
        }
        for (auto [d, p] : dirs)
        {
            auto [dr, dc] = p;
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (seen[nr][nc] || grid[nr][nc] == '#') continue;
            seen[nr][nc] = 1;
            path[nr][nc] = d;
            cout << nr << ' ' << nc << '\n';
            q.push({nr, nc});
        }
    }
    reverse(all(ret));
    cout << (ret.empty() ? "NO" : "YES") << '\n';
    if (!ret.empty())
    {
        cout << ret.size() << '\n';
        for (char x : ret)
        {
            cout << x;
        }
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
