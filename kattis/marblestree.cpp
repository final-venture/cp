#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
vector<vector<int>> adj;
vector<int> box;
vector<int> dp;

int dfs(int node, int par) {
    int ret = box[node] - 1;
    for (int nei : adj[node]) {
        if (nei == par) {
            continue;
        }
        ret += dfs(nei, node);
    }
    return dp[node] = ret;
}

void solve()
{
    adj.clear();
    adj.resize(n + 1);
    box.assign(n + 1, 0);
    dp.assign(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        int v, m, d;
        cin >> v >> m >> d;
        box[v] = m;
        for (int j = 0; j < d; ++j) {
            int x;
            cin >> x;
            adj[v].push_back(x);
            adj[x].push_back(v);
        }
    }

    dfs(1, -1);
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret += abs(dp[i]);
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        solve();
    }
    return 0;
}
