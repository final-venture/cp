#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<vector<int>> adj;
const int MAXD = 2e5 + 5;
vector<int> depth;
int n, k;

int dfs(int node, int par, int m) {
    depth[node] = 0;
    int ret = 0;
    for (int nei : adj[node]) {
        if (nei == par) {
            continue;
        }
        ret += dfs(nei, node, m);
        depth[node] = max(depth[node], 1 + depth[nei]);
    }
    if (depth[node] >= m - 1 && par != 1 && node != 1) {
        depth[node] = -1;
        ++ret;
    }
    return ret;
}

bool check(int m) {
    int moves = dfs(1, -1, m);
    if (moves <= k) {
        return true;
    }
    else {
        return false;
    }
}

void solve()
{
    cin >> n >> k;
    adj.clear();
    adj.resize(n + 1);
    depth.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    int l = 1, r = MAXD;
    int ret = MAXD;
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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
