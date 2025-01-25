#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

void solve()
{
    int n;
    cin >> n;
    vector<set<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        ++deg[u];
        ++deg[v];
    }
    int c1 = 0;
    for (int u = 1; u <= n; ++u)
    {
        for (auto &v : adj[u])
        {
            c1 = max(c1, deg[u] + deg[v] - 2);
        }
    }

    vector<pair<int, int>> sorted(n);
    for (int i = 1; i <= n; ++i)
    {
        sorted[i - 1] = {deg[i], i};
    }
    sort(sorted.begin(), sorted.end(), greater<>());
    int c2 = 0;
    for (int i = 0; i < n; ++i)
    {
        int u = sorted[i].second;
        for (int j = i + 1; j < n; ++j)
        {
            int v = sorted[j].second;
            if (adj[u].find(v) != adj[u].end())
                continue;
            c2 = max(c2, sorted[i].first + sorted[j].first - 1);
            break;
        }
    }
    // cout << c1 << ' ' << c2 << '\n';
    cout << max(c1, c2) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
