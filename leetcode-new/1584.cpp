// Kruskal's Algorithm
class UF
{
private:
    vector<int> par;
    vector<int> rank;

public:
    UF(int n)
    {
        for (int i = 0; i < n; i++)
        {
            par.push_back(i);
        }
        rank = vector<int>(n, 1);
    }
    int find(int x)
    {
        int p = par[x];
        while (p != par[p])
        {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    void unite(int x1, int x2)
    {
        int p1 = find(x1);
        int p2 = find(x2);
        if (p1 == p2)
            return;
        if (rank[p2] > rank[p1])
        {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        else
        {
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 1)
            return 0;

        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int mdist = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                edges.push_back({mdist, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        UF uf(n);
        int res = 0;

        for (auto &x : edges)
        {
            int mdist = x[0];
            int start = x[1];
            int end = x[2];
            if (uf.find(start) != uf.find(end))
            {
                uf.unite(start, end);
                res += mdist;
            }
        }
        return res;
    }
};

// Prim's Algorithm
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int m_dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[j].push_back({m_dist, i});
                adj[i].push_back({m_dist, j});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> seen(n, 0);
        pq.push({0, 0});
        int res = 0;
        while (!pq.empty())
        {
            auto &x = pq.top();
            int dist = x.first;
            int node = x.second;
            pq.pop();
            if (seen[node])
                continue;
            res += dist;
            seen[node] = 1;
            for (auto &nei : adj[node])
            {
                int neinode = nei.second;
                if (seen[neinode])
                    continue;
                pq.push(nei);
            }
        }

        return res;
    }
};
