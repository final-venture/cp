#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int v, e, k;
    cin >> v >> e >> k;
    vector<int> is_grounded(v + 1, 0);
    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        is_grounded[x] = 1;
    }
    vector<vector<pair<int, int>>> adj(v + 1);
    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    vector<pair<int, int>> dists(v + 1, {2e9, -1});
    for (int i = 1; i <= v; ++i)
    {
        if (is_grounded[i])
        {
            pq.push({0, i, i});
        }
    }
    int ret = 2e9;
    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        int dist = vec[0], node = vec[1], from = vec[2];
        pq.pop();
        if (dists[node].second != -1 && dists[node].second != from)
        {
            ret = min(ret, dist + dists[node].first);
            continue;
        }
        if (dists[node].second == from)
        {
            continue;
        }
        dists[node].first = dist;
        dists[node].second = from;
        for (auto &[neiDist, neiNode] : adj[node])
        {
            pq.push({dist + neiDist, neiNode, from});
        }
    }
    cout << ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
