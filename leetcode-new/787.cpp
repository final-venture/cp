class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &x : flights)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }
        queue<vector<int>> q;
        vector<int> dist(n, 1e8);
        q.push({0, src, 0});
        while (!q.empty())
        {
            auto &x = q.front();
            int layer = x[0], node = x[1], cost = x[2];
            q.pop();

            if (layer > k)
                continue;
            for (auto &[neinode, neicost] : adj[node])
            {
                if (neicost + cost < dist[neinode])
                {
                    dist[neinode] = neicost + cost;
                    q.push({layer + 1, neinode, neicost + cost});
                }
            }
        }
        return (dist[dst] == 1e8) ? -1 : dist[dst];
    }
};
