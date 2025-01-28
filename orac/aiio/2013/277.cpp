#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

class UF
{
private:
    vector<int> par;
    vector<int> rank;

public:
    UF(int n)
    {
        par.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
        rank.resize(n, 1);
    }
    // No idea why this doesn't work when using recursive version (stack overflow on sample case)
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
        if (rank[p1] > rank[p2])
        {
            par[p2] = par[p1];
        }
        else if (rank[p1] < rank[p2])
        {
            par[p1] = par[p2];
        }
        else
        {
            par[p1] = par[p2];
            ++rank[p2];
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> city2country(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> city2country[i];
    }
    vector<vector<vector<int>>> national(n + 1);
    vector<vector<int>> international;
    int total = 0;
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        total += c;
        if (city2country[u] == city2country[v])
        {
            national[city2country[u]].push_back({c, u, v});
        }
        else
        {
            international.push_back({c, u, v});
        }
    }
    UF uf(n + 1);
    int ret = 0;
    for (auto &nation : national)
    {
        sort(nation.begin(), nation.end());
        for (auto &flight : nation)
        {
            int c = flight[0], u = flight[1], v = flight[2];
            if (uf.find(u) != uf.find(v))
            {
                uf.unionn(u, v);
                ret += c;
            }
        }
    }
    sort(international.begin(), international.end());
    for (auto &flight : international)
    {
        int c = flight[0], u = flight[1], v = flight[2];
        if (uf.find(u) != uf.find(v))
        {
            uf.unionn(u, v);
            ret += c;
        }
    }
    cout << total - ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
