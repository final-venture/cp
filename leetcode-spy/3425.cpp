class Solution
{
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> nums;
    vector<pair<int, int>> lst;
    vector<pair<int, int>> dp;
    vector<pair<int, int>> lim;

    void dfs(int node, int par, int layer, int dist)
    {
        if (par == -1)
        {
            dp[node] = {0, 1};
            lim[node] = {0, -1};
            lst[nums[node]] = {0, 0};
            for (auto &[neiDist, neiNode] : adj[node])
            {
                if (neiNode == par)
                    continue;
                lst[nums[node]].first += neiDist;
                dfs(neiNode, node, layer + 1, dist + neiDist);
                lst[nums[node]].first -= neiDist;
            }
            lst[nums[node]] = {-1, -1};
            return;
        }
        else
        {
            if (lst[nums[node]].first != -1)
            {
                lim[node] = max(lim[par], lst[nums[node]]);
                dp[node] = {dist - lim[node].first, layer - lim[node].second};
                auto tmp = lst[nums[node]];
                lst[nums[node]] = {dist, layer};
                for (auto &[neiDist, neiNode] : adj[node])
                {
                    if (neiNode == par)
                        continue;
                    lst[nums[node]].first += neiDist;
                    dfs(neiNode, node, layer + 1, dist + neiDist);
                    lst[nums[node]].first -= neiDist;
                }
                lst[nums[node]] = tmp;
                return;
            }
            else
            {
                lim[node] = max(lim[par], lst[nums[node]]);
                dp[node] = {dist - lim[node].first, layer - lim[node].second};
                lst[nums[node]] = {dist, layer};
                for (auto &[neiDist, neiNode] : adj[node])
                {
                    if (neiNode == par)
                        continue;
                    lst[nums[node]].first += neiDist;
                    dfs(neiNode, node, layer + 1, dist + neiDist);
                    lst[nums[node]].first -= neiDist;
                }
                lst[nums[node]] = {-1, -1};
                return;
            }
        }
    }

    vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
    {
        int n = nums.size();
        adj.resize(n);
        dp.resize(n);
        lim.resize(n);
        lst.resize(5e4 + 5, {-1, -1});
        this->nums = nums;
        for (auto &vec : edges)
        {
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        dfs(0, -1, 0, 0);

        pair<int, int> ans = dp[0];

        for (int i = 1; i < n; i++)
        {
            if (ans.first < dp[i].first)
            {
                ans = dp[i];
            }
            else if (ans.first == dp[i].first && dp[i].second < ans.second)
            {
                ans = dp[i];
            }
        }

        return vector<int>({ans.first, ans.second});
    }
};
