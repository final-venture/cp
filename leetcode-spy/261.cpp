class Solution
{
private:
    int n;
    vector<int> par;
    vector<int> rank;
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
        int p1 = find(x1), p2 = find(x2);
        if (rank[x2] > rank[x1])
        {
            par[x1] = p2;
            rank[x2] += rank[x1];
        }
        else
        {
            par[x2] = p1;
            rank[x1] += rank[x2];
        }
    }

public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        if (edges.size() >= n)
            return false;
        if (n == 1)
            return true;

        this->n = n;
        par = vector<int>(n);
        rank = vector<int>(n, 1);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
        for (const vector<int> &edge : edges)
        {
            unite(edge[0], edge[1]);
        }
        for (int i = 1; i < n; ++i)
        {
            if (par[i] != par[i - 1])
                return false;
        }
        return true;
    }
};
