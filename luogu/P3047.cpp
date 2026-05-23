#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// we only consider cows moving up towards their ancestor.
// So for a node rooted at i, i has the correct answer.
// Reroot the tree for all nodes, and compute each of their final answer.

int n, k;
vector<vector<int>> adj;
vector<vector<int>> dpIn;
vector<vector<int>> dpOut;
vector<int> c;

void dfsIn(int node, int par) {
    dpIn[node].assign(k + 1, 0);
    dpIn[node][0] = c[node];

    for (int nei : adj[node]) {
        if (nei == par) {
            continue;
        }
        dfsIn(nei, node);
        for (int j = 1; j < k + 1; ++j) {
            dpIn[node][j] += dpIn[nei][j - 1];
        }
    }
}

void dfsOut(int node, int par) {
    for (int nei : adj[node]) {
        if (nei == par) {
            continue;
        }

        dpOut[nei].assign(k + 1, 0);

        // total cows that can move from me to nei is:
        //  sum of dpOut[node][0 .. k - 1]
        for (int j = 0; j <= k - 1; ++j) {
            int cowsCanMoveToNei = dpIn[node][j] + dpOut[node][j];
            dpOut[nei][j + 1] = cowsCanMoveToNei;
        }

        // total cows that moved up to me in this range from nei's subtree is:
        //  sum of dpIn[nei][0 .. k - 2]
        int cowsCameFromNeiSubtree = 0;
        for (int j = 0; j <= k - 2; ++j) {
            dpOut[nei][j + 2] -= dpIn[nei][j];
        }

        dfsOut(nei, node);
    }
}

void solve()
{
    cin >> n >> k;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    c.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    dpIn.resize(n + 1);
    dpOut.resize(n + 1);
    dfsIn(1, -1);
    dpOut[1].assign(k + 1, 0);
    dfsOut(1, -1);

    // the result for node i is sum of result[i][0..k]
    // where result[i][j] = dpIn[i][j] + dpOut[i][j].
    for (int i = 1; i <= n; ++i) {
        int ret = 0;
        for (int j = 0; j <= k; ++j) {
            ret += dpIn[i][j] + dpOut[i][j];
        }
        cout << ret << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
