class Solution
{
private:
    int ret = 0;
    long long dfs(int node, int par, vector<vector<int>> &adj, vector<int> &cost)
    {
        long long maxx = 0, maxxcnt = 0;
        for (int nei : adj[node])
        {
            if (nei == par)
                continue;
            long long cand = dfs(nei, node, adj, cost);
            if (cand > maxx)
            {
                maxx = cand;
                maxxcnt = 1;
            }
            else if (cand == maxx)
            {
                ++maxxcnt;
            }
        }
        ret += (adj[node].size() - 1 - maxxcnt);
        return (long long)maxx + cost[node];
    }

public:
    int minIncrease(int n, vector<vector<int>> &edges, vector<int> &cost)
    {
        vector<vector<int>> adj(n);
        for (vector<int> &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, adj, cost);
        return ret + 1;
    }
};
