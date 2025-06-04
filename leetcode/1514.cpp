class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<vector<pair<double, int>>> adj(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({succProb[i], v});
            adj[v].push_back({succProb[i], u});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> probs(n, 0);
        pq.push({1, start_node});
        probs[start_node] = 1;
        while (!pq.empty())
        {
            auto [prob, node] = pq.top();
            pq.pop();
            if (probs[node] < prob)
                continue;
            for (auto &[neiProb, neiNode] : adj[node])
            {
                if (prob * neiProb > probs[neiNode])
                {
                    probs[neiNode] = prob * neiProb;
                    pq.push({prob * neiProb, neiNode});
                }
            }
        }
        return probs[end_node];
    }
};
