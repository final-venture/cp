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
    vector<int> dists_d(n + 1, 1e15);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {1, 0}});
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second.first;
        int discount = pq.top().second.second;
        pq.pop();
        if (discount && dists_d[node] < dist) continue;
        if (!discount && dists[node] < dist) continue;
        for (auto [neiDist, neiNode] : adj[node])
        {
            int newDist = dist + neiDist;
            if (!discount)
            {
                if (newDist < dists[neiNode])
                {
                    dists[neiNode] = newDist;
                    pq.push({dists[neiNode], {neiNode, 0}});
                }
                newDist = dist + neiDist / 2;
                if (newDist < dists_d[neiNode])
                {
                    dists_d[neiNode] = newDist;
                    pq.push({dists_d[neiNode], {neiNode, 1}});
                }
            }
            else
            {
                if (newDist < dists_d[neiNode])
                {
                    dists_d[neiNode] = newDist;
                    pq.push({dists_d[neiNode], {neiNode, 1}});
                }
            }
        }
    }
    cout << min(dists[n], dists_d[n]) << '\n';
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
