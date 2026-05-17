#include <bits/stdc++.h>
#define int ll
#define ll long long

using namespace std;

struct Edge
{
    int u, v, k, t, x;
};

int m, a;
vector<Edge> edges;

struct UF
{
    vector<int> par;
    vector<int> rank;
    UF(int n)
    {
        par.resize(n);
        rank.resize(n, 0);
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
        return par[p];
    }
    void unionn(int x1, int x2)
    {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2)
            return;
        if (rank[p1] < rank[p2])
        {
            par[p1] = par[p2];
        }
        else if (rank[p1] > rank[p2])
        {
            par[p2] = par[p1];
        }
        else
        {
            par[p2] = par[p1];
            ++rank[p1];
        }
    }
};

bool check(int time)
{
    vector<pair<int, pair<int, int>>> cur_edges;
    for (int i = 0; i < m; ++i)
    {
        int error = max(0LL, edges[i].k - (time / edges[i].t) * edges[i].x);
        cur_edges.push_back({error, {edges[i].u, edges[i].v}});
    }
    sort(cur_edges.begin(), cur_edges.end());

    UF uf(100050);
    int total_error = 0;

    for (auto &edge : cur_edges)
    {
        if (uf.find(edge.second.first) != uf.find(edge.second.second))
        {
            uf.unionn(edge.second.first, edge.second.second);
            total_error += edge.first;
            if (total_error > a)
                return false;
        }
    }

    return true;
}

void solve()
{
    cin >> m >> a;
    edges.resize(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].k >> edges[i].t >> edges[i].x;
    }

    int l = 0, r = 2e12;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
