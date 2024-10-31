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

public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        int res = 0;
        this->n = n;
        rank = vector<int>(n, 1);
        par = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
        for (vector<int> &edge : edges)
        {
            unite(edge[0], edge[1]);
        }
        set<int> parSet;
        for (auto p : par)
        {
            parSet.insert(find(p));
        }
        return parSet.size();
    }
};
