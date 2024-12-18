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
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> dists(n + 1, 1e15);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dists[1] = 0;
    while (!pq.empty())
    {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dists[node] < dist) continue;
        for (auto [neiDist, neiNode] : adj[node])
        {
            int newDist = dist + neiDist;
            if (newDist < dists[neiNode])
            {
                dists[neiNode] = newDist;
                pq.push({newDist, neiNode});
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << dists[i] << ' ';
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
