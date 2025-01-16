#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

int s;
int n, st;
int t;
vector<int> noSong(20005, 1);
vector<vector<pair<int, int>>> adj;
vector<vector<int>> dists;

void solve()
{
    cin >> s;
    for (int i = 0; i < s; ++i)
    {
        int x;
        cin >> x;
        noSong[x] = 0;
    }
    cin >> n >> st;
    cin >> t;
    adj.resize(n + 1);
    for (int i = 0; i < t; ++i)
    {
        int u, v, m;
        cin >> u >> v >> m;
        adj[u].push_back({m, v});
        adj[v].push_back({m, u});
    }
    dists.resize(n + 1, vector<int>(s + 1, 1e9));                                               // dists[i][j] is min eggs on car at node i after j edges have been traversed
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; // dist, node, stops
    pq.push({0, {st, 0}});
    dists[st][0] = 0;

    while (!pq.empty())
    {
        auto [eggs, p] = pq.top();
        auto &[node, stops] = p;
        pq.pop();

        if (dists[node][stops] < eggs)
        {
            continue;
        }

        for (auto &[neiSong, neiNode] : adj[node])
        {
            int newEggs = eggs + noSong[neiSong];
            if (stops + 1 <= s && newEggs < dists[neiNode][stops + 1])
            {
                dists[neiNode][stops + 1] = newEggs;
                pq.push({newEggs, {neiNode, stops + 1}});
            }
        }
    }

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < s + 1; ++j)
        {
            cout << dists[i][j] << ' ';
        }
        cout << '\n';
    }
    // cout << dists[st][s];
}

signed main()
{
#ifndef LOCAL
    freopen("drivein.txt", "r", stdin);
    freopen("driveout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
