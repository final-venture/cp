#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    int st, ed;
    cin >> st >> ed;
    vector<int> disc(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> disc[i];
    }
    int k;
    cin >> k;
    vector<vector<pair<int, int>>> adj;
    for (int i = 0; i < k; ++i)
    {
        int u, v, w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    priority_queue < pair < int,
}

signed main()
{
#ifndef LOCAL
    freopen("trains.in", "r", stdin);
    freopen("trains.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
