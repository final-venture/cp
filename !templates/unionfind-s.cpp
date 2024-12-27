class UF
{
private:
    vector<int> par;
    vector<int> size;
public:
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
        if (p1 == p2) return;
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
