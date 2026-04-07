#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<int> a;
vector<vector<int>> adj;
vector<int> summ;
vector<int> cost;
vector<int> opCost;
vector<int> depth;

// cost[i] = sum(summ[j] + cost[j] for j in {children of i})
void dfs(int node, int par) {
    summ[node] = a[node];
    int bestOpIncrease = 0;
    int maxDepth1 = 0, maxDepth2 = 0;
    for (int nei : adj[node]) {
        if (nei == par) {
            continue;
        }
        dfs(nei, node);
        summ[node] += summ[nei];
        cost[node] += cost[nei] + summ[nei];
        opCost[node] += cost[nei] + summ[nei];
        if (depth[nei] + 1 >= maxDepth1) {
            maxDepth2 = maxDepth1;
            maxDepth1 = depth[nei] + 1;
        }
        else if (depth[nei] + 1 > maxDepth2) {
            maxDepth2 = depth[nei] + 1;
        }
        bestOpIncrease = max(bestOpIncrease, opCost[nei] - cost[nei]);
    }

    opCost[node] += bestOpIncrease;
    // if (node == 3) {
    //     cout << opCost[node] << '\n';
    // }
    depth[node] = maxDepth1;

    for (int nei : adj[node]) {
        if (nei == par) {
            continue;
        }
        int validDepth = (depth[nei] + 1 == maxDepth1) ? maxDepth2 : maxDepth1;
        // if (node == 3) {
        //     cout << summ[nei] << ' ' << validDepth << '\n';
        // }
        opCost[node] = max(opCost[node], cost[node] + summ[nei] * validDepth);
    }
}

void solve()
{
    int n;
    cin >> n;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    summ.assign(n + 1, 0);
    cost.assign(n + 1, 0);
    opCost.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    dfs(1, -1);
    // for (auto x : summ) {
    //     cout << x << ' ';
    // }
    // cout << '\n';
    // for (auto x : cost) {
    //     cout << x << ' ';
    // }
    // for (int i = 1; i <= n; ++i) {
    //     cout << cost[i] << ' ';
    // }
    // cout << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << max(cost[i], opCost[i]) << ' ';
    }
    cout << '\n';
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
