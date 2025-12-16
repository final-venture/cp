class Solution
{
private:
    vector<vector<int>> adj;
    vector<int> present;
    vector<int> future;
    int n;
    int dp1[160][160][161][2];
    int dp2[160][161][2];

    int processChildren(int node, int child, int rem, int disc)
    {
        if (child >= adj[node].size())
        {
            return 0;
        }
        if (dp1[node][child][rem][disc] != -1)
        {
            return dp1[node][child][rem][disc];
        }
        int ret = INT_MIN;
        for (int i = 0; i <= rem; ++i)
        {
            int cand = processChildren(node, child + 1, rem - i, disc) + dfs(adj[node][child], i, disc);
            ret = max(ret, cand);
        }
        return dp1[node][child][rem][disc] = ret;
    }

    int dfs(int node, int rem, int disc)
    {
        if (rem < 0)
        {
            return 0;
        }
        if (dp2[node][rem][disc] != -1)
        {
            return dp2[node][rem][disc];
        }
        int take = 0;
        int cost = disc ? present[node] / 2 : present[node];
        if (rem >= cost)
        {
            take = (future[node] - cost) + processChildren(node, 0, rem - cost, 1);
        }
        int notTake = processChildren(node, 0, rem, 0);
        return dp2[node][rem][disc] = max(take, notTake);
    }

public:
    int maxProfit(int n, vector<int> &present, vector<int> &future, vector<vector<int>> &hierarchy, int budget)
    {
        adj.resize(n);
        this->future = future;
        this->present = present;
        for (auto &h : hierarchy)
        {
            int u = h[0] - 1, v = h[1] - 1;
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; ++i)
        {
            for (int r = 0; r <= budget; ++r)
            {
                dp2[i][r][0] = -1;
                dp2[i][r][1] = -1;
            }

            int degree = adj[i].size();
            for (int c = 0; c <= degree; ++c)
            {
                for (int r = 0; r <= budget; ++r)
                {
                    dp1[i][c][r][0] = -1;
                    dp1[i][c][r][1] = -1;
                }
            }
        }

        return dfs(0, budget, 0);
    }
};
