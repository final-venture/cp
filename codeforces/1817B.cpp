#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> par(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int u = 1; u <= n; ++u) {
        if (adj[u].size() < 4) {
            continue;
        }

        int minCycleLen = 1e9;
        for (int uNei : adj[u]) {
            vector<int> visitedNodes;
            queue<pair<int, int>> q;
            q.push({1, uNei});
            par[uNei] = u;
            visitedNodes.push_back(uNei);
            while (!q.empty()) {
                auto [currCycleLen, bfsNode] = q.front();
                // cout << currCycleLen << ' ' << bfsNode << '\n';
                q.pop();
                if (bfsNode == u) {
                    minCycleLen = min(minCycleLen, currCycleLen);
                    cout << "YES" << '\n';
                    cout << minCycleLen + 2 << '\n';
                    int curr = u;
                    unordered_set<int> nodesInCycle;
                    while (true) {
                        cout << curr << ' ' << par[curr] << '\n';
                        nodesInCycle.insert(curr);
                        nodesInCycle.insert(par[curr]);
                        curr = par[curr];
                        if (curr == u) {
                            int cnt = 0;
                            for (int nei : adj[u]) {
                                if (!nodesInCycle.contains(nei)) {
                                    cout << u << ' ' << nei << '\n';
                                    ++cnt;
                                }
                                if (cnt >= 2) {
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    return;
                }
                for (int bfsNei : adj[bfsNode]) {
                    if (bfsNode == uNei && bfsNei == u) {
                        continue;
                    }
                    if (!par[bfsNei]) {
                        par[bfsNei] = bfsNode;
                        visitedNodes.push_back(bfsNei);
                        q.push({currCycleLen + 1, bfsNei});
                    }
                }
            }
            for (auto x : visitedNodes) {
                par[x] = 0;
            }
        }
    }

    cout << "NO" << '\n';
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
