#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define int ll

const int inf = 1e15;

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
    vector<int> dists(n + 1, -inf);
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; ++i)
    {
        int a, b, x;
        cin >> a >> b >> x;
        edges.push_back({x, {a, b}});
    }
    dists[1] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (auto [dist, p] : edges)
        {
            auto [u, v] = p;
            if (dists[u] == -inf) continue;
            if (dists[u] + dist > dists[v])
            {
                dists[v] = dist + dists[u];
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (auto [dist, p] : edges)
        {
            auto [u, v] = p;
            if (dists[u] == -inf) continue;
            // dists[v] = min(dists[v], inf);
            if (dists[u] + dist > dists[v])
            {
                dists[v] = inf;
            }
        }
    }
    // for (int x : dists) cout << x << ' ';
    // cout << '\n';
    if (dists[n] == inf) cout << -1 << '\n';
    else cout << dists[n] << '\n';
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
