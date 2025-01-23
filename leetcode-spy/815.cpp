class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        int n = routes.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < routes[i].size(); ++j)
            {
                adj[routes[i][j]].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        q.push({0, source});
        vector<int> seen(505, 0);
        while (!q.empty())
        {
            auto [dist, node] = q.front();
            q.pop();
            if (node == target)
                return dist;
            for (auto &stop : adj[node])
            {
                if (seen[stop])
                    continue;
                seen[stop] = 1;
                for (auto &neiNode : routes[stop])
                {
                    q.push({dist + 1, neiNode});
                }
            }
        }
        return -1;
    }
};
