#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

void solve()
{
    int n;
    cin >> n;
    vector<int> pfx(n, 0);
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n - 1; ++i)
    {
        int d;
        cin >> d;
        adj[i].push_back({d, i + 1});
        adj[i + 1].push_back({d, i});
        pfx[i] = d;
        pfx[i] += pfx[i - 1];
    }
    int a, b, q;
    cin >> a;
    vector<int> dists1(n + 1, 1e18);
    for (int i = 0; i < a; ++i)
    {
        int x, k;
        cin >> x >> k;
        adj[1].push_back({k, x});
        adj[x].push_back({k, 1});
    }
    cin >> b;
    vector<int> distsn(n + 1, 1e18);
    for (int i = 0; i < b; ++i)
    {
        int x, k;
        cin >> x >> k;
        adj[n].push_back({k, x});
        adj[x].push_back({k, n});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dists1[1] = 0;
    while (!pq.empty())
    {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dists1[node] < dist)
        {
            continue;
        }
        for (auto &[neiDist, neiNode] : adj[node])
        {
            if (dist + neiDist < dists1[neiNode])
            {
                dists1[neiNode] = dist + neiDist;
                pq.push({dist + neiDist, neiNode});
            }
        }
    }
    pq.push({0, n});
    distsn[n] = 0;
    while (!pq.empty())
    {
        auto [dist, node] = pq.top();
        pq.pop();
        if (distsn[node] < dist)
        {
            continue;
        }
        for (auto &[neiDist, neiNode] : adj[node])
        {
            if (dist + neiDist < distsn[neiNode])
            {
                distsn[neiNode] = dist + neiDist;
                pq.push({dist + neiDist, neiNode});
            }
        }
    }
    cin >> q;
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        // pfx[1] = 1 ==> 2
        // pfx[2] = 1 ==> 3
        // 1: s ==> t = pfx[t - 1] - pfx[s - 1];
        // 2: s ==> 1 ==> t = pfx[s - 1] + one2x[t];
        // 3: s ==> n ==> t = pfx[n - 1] - pfx[s - 1] + n2x[t];
        int c1 = pfx[t - 1] - pfx[s - 1];
        int c2 = pfx[s - 1] + dists1[t];
        int c3 = pfx[n - 1] - pfx[s - 1] + distsn[t];
        int c4 = distsn[s] + distsn[t];
        int c5 = dists1[s] + dists1[t];
        // cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
        int ret = min({c1, c2, c3, c4, c5});
        cout << ret << '\n';
    }
    // cout << distsn[4] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
