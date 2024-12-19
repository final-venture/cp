#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define int ll

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
    vector<pair<int, pair<int, int>>> edges;
    vector<int> dists(n + 1, 1e14);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    dists[1] = 0;
    vector<int> par(n + 1, -1);
    int x = -1;
    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (auto edge : edges)
        {
            int dist = edge.first;
            auto [u, v] = edge.second;
            // if (dists[u] == 1e14) continue;
            if (dist + dists[u] < dists[v])
            {
                dists[v] = dist + dists[u];
                par[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) cout << "NO" << '\n';
    else
    {
        for (int i = 0; i < n; ++i)
        {
            x = par[x];
        }
        vector<int> ret;
        cout << "YES" << '\n';
        int node = x;
        ret.pb(node);
        while (!(node == x && ret.size() > 1))
        {
            node = par[node];
            ret.pb(node);
        }
        reverse(all(ret));
        for (int x : ret) cout << x << ' ';
    }
    // cout << '\n';
    // for (int x : par) cout << x << ' ';
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
