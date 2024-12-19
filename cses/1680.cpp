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
vector<int> dists;
vector<int> seen;
vector<int> to;

void dfs(int node)
{
    if (seen[node]) return;
    seen[node] = 1;
    for (int nei : adj[node])
    {
        dfs(nei);
        if ((dists[nei] != -1) && (dists[nei] + 1 > dists[node]))
        {
            dists[node] = dists[nei] + 1;
            to[node] = nei;
        }
    }
}

void solve()
{

    cin >> n >> m;
    adj.resize(n + 1);
    dists.resize(n + 1, -1);
    seen.resize(n + 1, 0);
    to.resize(n + 1, 0);
    dists[n] = 1;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    dfs(1);
    // for (int x : dists) cout << x << endl;
    if (dists[1] == -1)
    {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    vector<int> ret;
    int curr = 1;
    ret.pb(1);
    // int dbg = 0;
    while (curr != n)
    {
        // if (dbg++ > 50) break;
        ret.pb(to[curr]);
        curr = to[curr];
    }
    cout << dists[1] << endl;
    for (int x : ret)
    {
        cout << x << ' ';
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
