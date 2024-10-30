class Solution
{
private:
    vector<int> par{};

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        for (int i = 0; i <= n; ++i)
        {
            par.push_back(i);
        }
        vector<int> rank(n + 1, 1);
        for (auto &x : edges)
        {
            if (!unionn(x[0], x[1], rank))
                return x;
        }
        return {};
    }

    int find(int n)
    {
        int p = par[n];
        while (p != par[p])
        {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool unionn(int a, int b, vector<int> &rank)
    {
        int pa = find(a), pb = find(b);
        if (pa == pb)
            return false;
        if (rank[pa] > rank[pb])
        {
            par[pb] = par[pa];
            rank[pa] += rank[pb];
        }
        else
        {
            par[pa] = par[pb];
            rank[pb] += rank[pa];
        }
        return true;
    }
};
