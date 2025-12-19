class UF
{
public:
    vector<int> par;
    vector<int> size;
    UF(int n)
    {
        par.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
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

    void unionn(int x1, int x2)
    {

        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2)
            return;
        if (size[p1] > size[p2])
        {
            par[p2] = par[p1];
            size[p1] += size[p2];
        }
        else // (size[p2] > size[p1])
        {
            par[p1] = par[p2];
            size[p2] += size[p1];
        }
    }
};

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        int maxT = -1;
        for (auto &m : meetings)
        {
            maxT = max(maxT, m[2]);
        }
        vector<vector<pair<int, int>>> t2meets(maxT + 1);
        for (auto &m : meetings)
        {
            int u = m[0], v = m[1], t = m[2];
            t2meets[t].push_back({u, v});
        }
        UF uf(n);
        uf.unionn(0, firstPerson);
        for (int t = 1; t <= maxT; ++t)
        {
            for (auto &m : t2meets[t])
            {
                auto [u, v] = m;
                uf.unionn(u, v);
            }
            for (auto &m : t2meets[t])
            {
                auto [u, v] = m;
                if (uf.find(u) != uf.find(0))
                {
                    uf.par[u] = u;
                    uf.par[v] = v;
                    uf.size[u] = 1;
                    uf.size[v] = 1;
                }
            }
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i)
        {
            if (uf.find(i) == uf.find(0))
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
