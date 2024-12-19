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
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    vector<int> path;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        ++indeg[b];
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!indeg[i]) q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        path.pb(node);
        for (int nei : adj[node])
        {
            --indeg[nei];
            if (!indeg[nei])
                q.push(nei);
        }
    }
    if (path.size() < n)
    {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    for (int x : path) cout << x << ' ';
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
