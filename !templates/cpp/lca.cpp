#include <bits/stdc++.h>

using namespace std;

struct LCA {
    int n, LOG;
    vector<vector<int>> up;
    vector<int> depth;

    // Pass the number of nodes, root node (0-indexed or 1-indexed), and adjacency list
    LCA(int n, int root, const vector<vector<int>>& adj) {
        this->n = n;
        LOG = 32 - __builtin_clz(n); // __builtin_clz finds the number of leading zeroes
        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);
        
        dfs(root, root, adj); // Populate up and depth arrays
    }

    void dfs(int v, int p, const vector<vector<int>>& adj) {
        up[v][0] = p;
        
        for (int j = 1; j < LOG; j++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }

        for (int u : adj[v]) {
            if (u != p) {
                depth[u] = depth[v] + 1;
                dfs(u, v, adj);
            }
        }
    }

    // TC: O(log n)
    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) 
            swap(u, v);

        // 1. Lift u to the same depth as v
        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; j++) {
            if ((diff >> j) & 1) {
                u = up[u][j];
            }
        }

        // In case u and v are the same node after lifting to same depth
        if (u == v) return u;

        // 2. Lift both u and v until their ancestors match
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0]; // Direct parent of u is the LCA
    }

    // Get distance between two nodes
    // TC: O(log n)
    int get_dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
    }
};
