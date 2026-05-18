#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// connect vertices with the same genre id
// connect vertices with same author id (O(n^2) worst case)
// run dfs with bitmask dp to find the longest hamilton path.

vector<vector<int>> adj;
unordered_map<string, vector<int>> nodes_with_genre, nodes_with_author;
const int FULL_MASK = (1 << 16) - 1;
const int MAXN = 16;
int dp[MAXN][FULL_MASK + 2];

int dfs(int node, int curr_mask) {
    if (1LL & (curr_mask >> node)) {
        return 0;
    }
    if (dp[node][curr_mask] != -1) {
        return dp[node][curr_mask];
    }
    int ret = 1;
    for (int nei : adj[node]) {
        int new_mask = curr_mask | (1 << node);
        ret = max(ret, 1 + dfs(nei, new_mask));
    }
    return dp[node][curr_mask] = ret;
}

void solve()
{
    int n;
    cin >> n;

    nodes_with_author.clear();
    nodes_with_genre.clear();
    for (int i = 0; i < n; ++i) {
        string genre;
        cin >> genre;
        string author;
        cin >> author;
        
        nodes_with_genre[genre].push_back(i);
        nodes_with_author[author].push_back(i);
    }

    adj.clear();
    adj.resize(n);
    for (auto& [genre, nodes] : nodes_with_genre) {
        int nodes_sz = nodes.size();
        for (int i = 0; i < nodes_sz; ++i) {
            for (int j = i + 1; j < nodes_sz; ++j) {
                int u = nodes[i];
                int v = nodes[j];
                // cout << u << ' ' << v << '\n';
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
    for (auto& [author, nodes] : nodes_with_author) {
        int nodes_sz = nodes.size();
        for (int i = 0; i < nodes_sz; ++i) {
            for (int j = i + 1; j < nodes_sz; ++j) {
                int u = nodes[i];
                int v = nodes[j];
                // cout << u << ' ' << v << '\n';
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        auto it = unique(adj[i].begin(), adj[i].end());
        adj[i].erase(it, adj[i].end());
    }

    memset(dp, -1, sizeof(dp));
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, dfs(i, 0));
    }
    cout << n - ret << '\n';
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
