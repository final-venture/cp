#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

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
public:
    vector<int> par;
    vector<int> rank;

    UF(int n)
    {
        par.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
        rank.resize(n, 1);
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
    vector<pair<int, int>> ret;
    cin >> n >> m;
    UF uf(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        uf.unionn(u, v);
    }
    vector<int> cc;
    for (int i = 1; i <= n; ++i)
    {
        if (i == uf.find(i))
        {
            // cout << i << ' ' << uf.find(i);
            cc.pb(i);
        }
    }
    // cout << '\n';
    // for (auto x : uf.par) cout << x << ' ';
    int nn = cc.size();
    cout << nn - 1 << '\n';
    for (int i = 1; i < nn; ++i)
    {
        cout << cc[0] << ' ' << cc[i] << '\n';
    }
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
