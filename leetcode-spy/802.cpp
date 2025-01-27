class Solution
{
public:
    vector<int> safe;
    vector<vector<int>> adj;
    vector<int> seen;
    int dfs(int node)
    {
        if (adj[node].empty())
        {
            return safe[node] = 1;
        }
        if (safe[node])
        {
            return 1;
        }
        if (seen[node])
        {
            return 0;
        }
        seen[node] = 1;
        int ok = 1;
        for (int nei : adj[node])
        {
            if (!dfs(nei))
                ok = 0;
        }
        return safe[node] = ok;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        adj = graph;
        safe.resize(n, 0);
        seen.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (!seen[i])
                dfs(i);
        }
        vector<int> ret;
        for (int i = 0; i < n; ++i)
        {
            if (safe[i])
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
