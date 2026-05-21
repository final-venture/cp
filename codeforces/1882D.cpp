#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// APPROACH = REROOTING
// solve the problem for one root, let's root it at node 1:
// intuitively, the best solution is to process the tree from the leaves to the root,
//  and make sure all values in a node's subtree is equal before moving onto ancestors.
// Specifically, for every node u we process which has parent p, we have to perform an operation
//  on node u, with c = val[u] ^ val[p]. 
// So, if we let dp_in[u] denote the min cost to make the value of every single node in the subtree of u
//  equal to val[u], then:
// dp_in[u] = dp_in[v] + sub_size[v] * (val[u] ^ val[v])

// rerooting process:
// We have already found the answer for root node 1.
// So we run a DFS starting from it.
// For some node u that we are currently at in our DFS, with children v:
// dp_out[v] = dp_out[u] - sub_size[v] * (val[v] ^ val[u]) + dp_in[v] + 
//  (n - sub_size[v]) * (val[v] ^ val[u]).

int n;
vector<int> val;
vector<int> dp_in;
vector<int> dp_out;
vector<int> sub_size;
vector<vector<int>> adj;

void dfs_in(int u, int par) {
    dp_in[u] = 0;
    sub_size[u] = 1;
    for (int v : adj[u]) {
        if (v == par) {
            continue;
        }
        dfs_in(v, u);
        dp_in[u] += dp_in[v] + sub_size[v] * (val[u] ^ val[v]);
        sub_size[u] += sub_size[v];
    }
}

void dfs_out(int u, int par) {
    for (int v : adj[u]) {
        if (v == par) {
            continue;
        }
        int c = val[u] ^ val[v];
        dp_out[v] = dp_out[u] + c * (n - 2 * sub_size[v]);
        dfs_out(v, u);
    }
}

void solve()
{
    cin >> n;
    val.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp_in.resize(n);
    dp_out.resize(n);
    sub_size.resize(n);

    dfs_in(0, -1);
    dp_out[0] = dp_in[0];
    dfs_out(0, -1);

    for (int x : dp_out) {
        cout << x << ' ';
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
