class UF
{
private:
    vector<int> par;
    vector<int> sz;
    // vector<int> minn;
public:
    UF(int n)
    {
        // minn.resize(n);
        par.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
            // minn[i] = i;
        }
        sz.resize(n, 1);
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
        if (sz[p1] < sz[p2])
        {
            sz[p2] += sz[p1];
            par[p1] = par[p2];
            // minn[p2] = min(minn[p1], minn[p2]);
        }
        else
        {
            sz[p1] += sz[p2];
            par[p2] = par[p1];
            // minn[p1] = min(minn[p1], minn[p2]);
        }
    }
    int getSz(int x)
    {
        return sz[x];
    }
    // int getMinn(int x)
    // {
    //     return minn[x];
    // }
};

// Think from the perspective of connected components.
// If a node from the same connected component is infected twice, obviously we don't want it.
// So we want to return the minimum idx representative of the biggest connected component uniquely infected by 1 component. Otherwise just return min ele of initial;
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        // unordered_set<int> init_set(initial.begin(), initial.end());
        UF uf(n);
        for (int u = 0; u < n; ++u)
        {
            for (int v = u + 1; v < n; ++v)
            {
                if (graph[u][v])
                {
                    uf.unionn(u, v);
                }
            }
        }

        vector<int> irc(n, 0); // representative count for all nodes in initial
        for (auto node : initial)
        {
            ++irc[uf.find(node)];
        }
        pair<int, int> sz_idx { -1, *min_element(initial.begin(), initial.end())};
        for (auto node : initial)
        {
            int rep = uf.find(node);
            int sz = uf.getSz(rep);
            if (irc[rep] == 1)
            {
                if (sz_idx.first < sz)
                {
                    sz_idx.first = sz;
                    sz_idx.second = node;
                }
                else if (sz_idx.first == sz && node < sz_idx.second)
                {
                    sz_idx.second = node;
                }
            }
        }
        return sz_idx.second;
    }
};
