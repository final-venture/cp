class Solution
{
private:
    vector<vector<int>> adj;
    vector<int> group;
    vector<long long> allCnt;
    vector<long long> dfs(int node, int par)
    {
        vector<long long> ret(21, 0);
        for (int nei : adj[node])
        {
            if (nei == par)
            {
                continue;
            }
            vector<long long> cand = dfs(nei, node);
            for (int i = 0; i < 21; ++i)
            {
                ret[i] += cand[i];
            }
        }
        ret[group[node]]++;
        if (!allCnt.empty())
        {
            for (int i = 1; i < 21; ++i)
            {
                long long toAdd = (allCnt[i] - ret[i]) * ret[i] * 1LL;
                ret[0] += toAdd;
            }
        }
        return ret;
    }

public:
    long long interactionCosts(int n, vector<vector<int>> &edges, vector<int> &group)
    {
        adj.resize(n);
        this->group = group;
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        allCnt = dfs(0, -1);
        return dfs(0, -1)[0];
    }
};
