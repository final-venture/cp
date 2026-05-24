#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int INF = 1e18;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> dists(n + 1, INF);
    for (int i = 0; i < m; ++i) {
        int u, v, y;
        cin >> u >> v >> y;
        adj[u].push_back({y, v});
        adj[v].push_back({y, u});
    }

    string currMask;
    currMask.assign(n + 1, '0');
    currMask[1] = '1';
    vector<string> maskOfGame;
    vector<int> timeOfGame;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dists[1] = 0;

    int timer = 0;
    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dist > dists[node]) {
            continue;
        }
        if (dist > timer) {
            maskOfGame.push_back(currMask.substr(1, n));
            timeOfGame.push_back(dist - timer);
            timer = dist;
        }

        if (node == n) {
            break;
        }
        
        currMask[node] = '1';

        for (auto [neiDist, neiNode] : adj[node]) {
            int newDist = dist + neiDist;
            if (newDist >= dists[neiNode]) {
                continue;
            }
            dists[neiNode] = newDist;
            pq.push({newDist, neiNode});
        }
    }

    if (dists[n] == INF) {
        cout << "inf\n";
    } 
    else {
        cout << dists[n] << " " << maskOfGame.size() << "\n";
        for (int i = 0; i < maskOfGame.size(); ++i) {
            cout << maskOfGame[i] << " " << timeOfGame[i] << "\n";
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
