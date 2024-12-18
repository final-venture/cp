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
int start_node = 0, end_node = 0;
vector<vector<int>> adj;
vector<int> seen;
vector<int> par;
vector<int> ret;

bool dfs(int node, int p)
{
    // cout << node << '\n';
    par[node] = p;
    for (int nei : adj[node])
    {
        if (nei == p) continue;
        if (seen[nei])
        {
            start_node = nei;
            end_node = node;
            ret.pb(start_node);
            return true;
        }
        else
        {
            seen[nei] = 1;
            if (dfs(nei, node)) return true;
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    int ok = 0;
    adj.resize(n + 1);
    par.resize(n + 1);
    seen.resize(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!seen[i])
        {
            seen[i] = 1;
            if (dfs(i, 0))
            {
                ok = 1;
                break;
            }
        }
    }
    if (ok)
    {
        while (end_node != start_node)
        {
            ret.pb(end_node);
            end_node = par[end_node];
        }
        ret.pb(start_node);
        reverse(all(ret));
        cout << ret.size() << '\n';
        for (int x : ret) cout << x << ' ';
    }
    else
    {
        cout << "IMPOSSIBLE" << '\n';
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
