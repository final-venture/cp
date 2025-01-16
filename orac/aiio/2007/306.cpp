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
    vector<int> discs(n + 1);
    vector<vector<int>> dists(n + 1, vector<int>(n + 1, 1e9));
    unordered_map<int, int> disc2idx;
    for (int i = 1; i <= n; ++i)
    {
        cin >> discs[i];
        if (disc2idx.find(discs[i]) == disc2idx.end())
        {
            disc2idx[discs[i]] = i;
        }
    }
    int k;
    cin >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < k; ++i)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u});
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {st, discs[st]}});
    dists[st][disc2idx[discs[st]]] = 0;

    while (!pq.empty())
    {
        // cout << "xdd" << '\n';
        auto [dist, p] = pq.top();
        auto &[node, disc] = p;
        pq.pop();

        if (dist > dists[node][disc2idx[disc]])
            continue;

        for (auto &[neiDist, neiNode] : adj[node])
        {
            int newDist = dist + max(0, neiDist - disc);
            int newDisc = max(disc, discs[neiNode]);
            if (newDist < dists[neiNode][disc2idx[newDisc]])
            {
                dists[neiNode][disc2idx[newDisc]] = newDist;
                pq.push({newDist, {neiNode, newDisc}});
            }
        }
    }
    int ret = 1e9;
    for (int i = 0; i <= n; ++i)
    {
        ret = min(ret, dists[ed][i]);
    }
    cout << ret;
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
