class Solution
{
private:
    vector<vector<pair<int, int>>> adj;
    int n;
    long long k;

    int check(long long t)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dists(n, 1e16);
        vector<int> lowests(n, 2e9);
        dists[0] = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();
            if (dist > dists[node])
            {
                continue;
            }
            if (node == n - 1)
                break;
            for (auto [neiDist, neiNode] : adj[node])
            {
                // cout << neiDist << '\n';
                if (neiDist < t)
                {
                    continue;
                }
                long long newDist = dist + neiDist;
                if (newDist >= dists[neiNode])
                {
                    continue;
                }
                dists[neiNode] = newDist;
                lowests[neiNode] = min({lowests[node], neiDist});
                pq.push({newDist, neiNode});
            }
        }
        if (dists[n - 1] > k)
        {
            return -1;
        }

        return lowests[n - 1];
    }

public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k)
    {
        this->k = k;
        n = online.size();
        adj.resize(n);
        for (auto &vec : edges)
        {
            int u = vec[0], v = vec[1], wt = vec[2];
            if (!online[u] || !online[v])
            {
                continue;
            }
            adj[u].push_back({wt, v});
        }

        long long l = 0, r = 2e9;
        int ret = -1;
        while (l < r)
        {
            long long m = l + (r - l) / 2;
            int cand = check(m);
            if (cand != -1)
            {
                ret = max(cand, ret);
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return ret;
    }
};
