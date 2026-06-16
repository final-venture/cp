// LCA to find number of edges between query pairs
// for odd parity, need count of 1,3,5,7... edges with weight 1
// if total number of edges is e, then its C(e, 1) + C(e, 3) + ...
// How to compute this efficiently?
// C(e, 1) + C(e, 3) + C(e, 5) + C(e, 7) + ...
// = e + e*(e-1)*(e-2) / 3! + e*(e-1)*(e-2)*(e-3)*(e-4) / 5!
// = 2^(e - 1)

class Solution {
private:
    const int LOG = 18;
    const int MAXN = 1e5 + 5;
    const int MOD = 1e9 + 7;
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;
    void dfs(int node, int par, int dep) {
        depth[node] = dep;
        up[node][0] = par;
        for (int j = 1; j < LOG; ++j) {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }
        for (int nei : adj[node]) {
            if (nei == par) {
                continue;
            }
            dfs(nei, node, dep + 1);
        }
    }

    long long bin_exp(long long base, long long exp) {
        long long ret = 1;
        while (exp > 0) {
            if (exp & 1) {
                ret *= base;
                ret %= MOD;
            }
            base *= base;
            base %= MOD;
            exp /= 2;
        }
        return ret;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = 2;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            n = max({n, u, v});
        }
        adj.resize(n + 5);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            n = max({n, u, v});
        }

        depth.resize(n + 5);
        up.resize(n + 5, vector<int>(LOG));
        dfs(1, 1, 0);

        // cout << depth[4] << ' ' << depth[5] << '\n';

        int q = queries.size();
        vector<int> ret(q);
        for (int i = 0; i < q; ++i) {
            int a = queries[i][0], b = queries[i][1];

            if (a == b) {
                ret[i] = 0;
                continue;
            }

            int distPOT = 0, finalDist = 0;
            // enforce that b is deeper
            if (depth[b] < depth[a]) {
                swap(a, b);
            }
            int diff = depth[b] - depth[a];
            finalDist += diff;
            for (int j = LOG - 1; j >= 0; --j) {
                if ((diff >> j) & 1) {
                    b = up[b][j];
                }
            }
            if (b != a) {
                for (int j = LOG - 1; j >= 0; --j) {
                    if (up[a][j] != up[b][j]) {
                        a = up[a][j];
                        b = up[b][j];
                        finalDist += (1 << (j + 1));
                        finalDist %= MOD;
                    }
                }
                finalDist += 2;
            }

            // finalDist += bin_exp(2, distPOT);
            long long combs = bin_exp(2, (finalDist - 1));
            ret[i] = combs;
        }
        return ret;
    }
};
