class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &edge : times)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({w, v});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        vector<int> seen(n + 1, 0);
        int ret = 0;
        while (!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();
            if (seen[node])
                continue;
            seen[node] = 1;
            ret = max(ret, dist);
            for (auto &[neiDist, neiNode] : adj[node])
            {
                if (seen[neiNode])
                    continue;
                pq.push({dist + neiDist, neiNode});
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!seen[i])
                return -1;
        }
        return ret;
    }
};
