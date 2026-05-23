#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n, m;
int k;
vector<vector<pair<int, int>>> adj;
vector<int> tPlaced;
vector<int> nodeOfOrder;
vector<int> tReady;
vector<vector<int>> sd;
vector<int> sdOrdersPfx;

bool check(int W) {
    vector<int> dp(k + 1, 1e18);
    dp[0] = 0;

    for (int i = 1; i <= k; ++i) {
        // This tracks the maximum value of (sdOrdersPfx[x] - tPlaced[x]) for x in [j..i]
        int maxXCost = -1e18;
        for (int j = i; j >= 1; --j) {
            // deliver the block between [j..i]

            maxXCost = max(maxXCost, sdOrdersPfx[j] - tPlaced[j]);
            int distToFirst = sd[1][nodeOfOrder[j]];
            int distBetween = sdOrdersPfx[i] - sdOrdersPfx[j];

            if (dp[j - 1] >= 1e18) {
                continue;

            }
            int tLeave = max(tReady[i], dp[j - 1]);
            int tDelivered = tLeave + distToFirst + distBetween;
            int maxWaitTime = tLeave + distToFirst - sdOrdersPfx[j] + maxXCost;

            if (maxWaitTime <= W) {
                int distBack = sd[nodeOfOrder[i]][1];
                int tReturned = tDelivered + distBack;
                dp[i] = min(dp[i], tReturned);
            }            
        }
    }

    if (dp[k] >= 1e18) {
        return false;
    }
    return true;
}

void dijkstra(int st) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, st});
    sd[st][st] = 0;
    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dist > sd[st][node]) {
            continue;
        }

        for (auto& [neiDist, neiNode] : adj[node]) {
            int newDist = dist + neiDist;
            if (newDist >= sd[st][neiNode]) {
                continue;
            }
            sd[st][neiNode] = newDist;
            pq.push({newDist, neiNode});
        }
    }
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }

    cin >> k;
    tPlaced.resize(k + 1);
    tReady.resize(k + 1);
    nodeOfOrder.resize(k + 1);
    for (int i = 1; i <= k; ++i) {
        int s, u, t;
        cin >> tPlaced[i] >> nodeOfOrder[i] >> tReady[i];
    }

    sd.resize(n + 1, vector<int>(n + 1, 1e18));
    for (int i = 1; i <= n; ++i) {
        dijkstra(i);
    }

    sdOrdersPfx.resize(k + 1);
    sdOrdersPfx[1] = 0; sdOrdersPfx[0] = 0;
    for (int i = 2; i <= k; ++i) {
        sdOrdersPfx[i] = sdOrdersPfx[i - 1] + sd[nodeOfOrder[i]][nodeOfOrder[i - 1]];
    }

    int l = 0, r = 1e18;
    int ret = 1e18;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            r = m - 1;
            ret = m;
        }
        else {
            l = m + 1;
        }
    }

    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
