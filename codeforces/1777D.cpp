#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MOD = 1e9 + 7;

int n;
vector<vector<int>> adj;
vector<int> h;

int mod_exp(int base, int exp) {
    int ret = 1;
    while (exp > 0) {
        if (exp & 1) {
            ret *= base;
            ret %= MOD;
        }
        base *= base;
        base %= MOD;
        exp /= 2;
    }
    return ret % MOD;
}

int dfs(int node, int par) {
    int ret = 0;
    for (int nei : adj[node]) {
        if (nei == par) {
            continue;
        }
        ret += dfs(nei, node);
        ret %= MOD;
        h[node] = max(h[node], 1 + h[nei]);
    }
    return (ret + (h[node] + 1) * mod_exp(2, n - 1)) % MOD;
}

void solve()
{
    cin >> n;
    adj.clear();
    adj.resize(n + 1);
    h.assign(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << (dfs(1, -1) % MOD) << '\n';
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
