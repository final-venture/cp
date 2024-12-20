#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9
#define int ll

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

class UF
{
private:
    vector<int> par;
    vector<int> rank;
public:
    UF(int n)
    {
        par.resize(n);
        rank.resize(n, 1);
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
        if (rank[p1] > rank[p2])
        {
            par[p2] = par[p1];
        }
        else if (rank[p2] > rank[p1])
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
    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, {a, b}};
    }
    UF uf(n + 1);
    sort(all(edges));
    int ret = 0;
    for (auto& edge : edges)
    {
        int wt = edge.first;
        auto [u, v] = edge.second;
        if (uf.find(u) != uf.find(v))
        {
            ret += wt;
            uf.unionn(u, v);
        }
    }
    int p = uf.find(1);
    for (int i = 1; i <= n; ++i)
    {
        if (uf.find(i) != p)
        {
            cout << "IMPOSSIBLE" << '\n';
            return;
        }
    }
    cout << ret << '\n';
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
