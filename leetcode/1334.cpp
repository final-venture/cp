class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        vector<vector<int>> dists(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        for (int i = 0; i < n; ++i)
        {
            pq.push({0, {i, i}});
            dists[i][i] = 0;
        }
        while (!pq.empty())
        {
            auto [dist, p] = pq.top();
            auto &[node, from] = p;
            pq.pop();
            if (dists[node][from] < dist)
                continue;
            for (auto &[neiDist, neiNode] : adj[node])
            {
                if (dist + neiDist < dists[neiNode][from])
                {
                    dists[neiNode][from] = dist + neiDist;
                    pq.push({dist + neiDist, {neiNode, from}});
                }
            }
        }
        int ret;
        int best = 111;
        for (int j = 0; j < n; ++j)
        {
            int cand = 0;
            for (int i = 0; i < n; ++i)
            {
                if (i == j)
                    continue;
                if (dists[i][j] <= distanceThreshold)
                    ++cand;
            }
            if (cand <= best)
            {
                ret = j;
                best = cand;
            }
        }
        return ret;
    }
};
