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
vector<vector<int>> adj;
vector<int> col;

bool dfs(int node, int c)
{
    col[node] = c;
    for (int nei : adj[node])
    {
        if (col[nei] == -1)
        {
            if (!dfs(nei, c ^ 3))
                return false;
        }
        else if (col[nei] == col[node])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    col.resize(n + 1, -1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int valid = 1;
    for (int i = 1; i < n + 1; ++i)
    {
        if (col[i] == -1 && !dfs(i, 1))
        {
            valid = 0;
            break;
        }
    }
    if (!valid)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        for (int i = 1; i < n + 1; ++i)
        {
            cout << col[i] << ' ';
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
