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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    unordered_map<int, vector<pair<int, int>>> adj;
    vector<int> pfx(n + 1, 0ll);
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i < n + 1; ++i)
    {
        pfx[i] = pfx[i - 1] + a[i];
    }
    for (int i = 1; i < n + 1; ++i)
    {
        adj[i].push_back({b[i], a[i]});
        if (i > 1) adj[i].push_back({i - 1, 0});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, 1e15);
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    int res = -1e15;
    for (int i = 1; i < n + 1; ++i)
    {
        res = max(res, pfx[i] - dist[i]);
    }
    cout << res << '\n';
}

signed main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
