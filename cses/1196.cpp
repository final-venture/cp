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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<multiset<int, greater<>>> dists(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dists[1].insert(0);
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if (i == 1 && j == 0) continue;
            dists[i].insert(1e15);
        }
    }
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (dist > *(dists[node].begin())) continue;
        for (auto [neiDist, neiNode] : adj[node])
        {
            int newDist = neiDist + dist;
            if (newDist < * (dists[neiNode].begin()))
            {
                dists[neiNode].insert(newDist);
                pq.push({newDist, neiNode});
                dists[neiNode].erase(dists[neiNode].begin());
            }
        }
    }
    // for (int i = 0; i <= n; ++i)
    // {
    //     for (auto rit = dists[i].rbegin(); rit != dists[i].rend(); ++rit)
    //     {
    //         cout << *rit << ' ';
    //     }
    //     cout << '\n';
    // }
    for (auto rit = dists[n].rbegin(); rit != dists[n].rend(); ++rit)
    {
        cout << *rit << ' ';
    }
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
