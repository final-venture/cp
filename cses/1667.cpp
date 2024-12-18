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
    vector<int> seen(n + 1, 0);
    vector<int> route(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    seen[1] = 1;
    while (!q.empty())
    {
        auto [node, par] = q.front();
        q.pop();
        route[node] = par;
        if (node == n) break;
        for (auto nei : adj[node])
        {
            if (seen[nei]) continue;
            seen[nei] = 1;
            q.push({nei, node});
        }
    }
    vector<int> ret;
    // for (int x : route) cout << x << ' ';
    while (route[n])
    {
        ret.pb(n);
        n = route[n];
    }
    int nn = ret.size();
    if (nn)
    {
        ret.pb(1);
        reverse(all(ret));
        cout << ret.size() << '\n';
        for (int x : ret) cout << x << ' '; 
    }
    else
    {
        cout << "IMPOSSIBLE";
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
