class Solution {
private:
    vector<vector<int>> adj;
    vector<int> tin;
    vector<int> low;
    vector<int> seen;
    vector<vector<int>> ret;
    int time = 0;
public:
    void dfs(int node, int par)
    {
        if (seen[node]) return;
        seen[node] = 1;
        tin[node] = time;
        low[node] = tin[node];
        ++time;
        for (int nei : adj[node])
        {
            if (nei == par) continue;
            dfs(nei, node);
            low[node] = min(low[node], low[nei]);
            if (low[nei] > tin[node])
            {
                ret.push_back({node, nei});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n); tin.resize(n); low.resize(n); seen.resize(n, 0);
        for (auto& x : connections)
        {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        return ret;
    }
};
