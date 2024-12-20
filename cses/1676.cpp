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

class UF // != TEMPLATE!! (UNION BY SIZE + GETMAX + GETCOMPONENTS)
{
private:
    vector<int> par;
    vector<int> size;
    int maxx = 1;
    int components;
public:
    UF(int n)
    {
        par.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
        components = n - 1;
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
            maxx = max(maxx, size[p1]);
        }
        else // (size[p2] > size[p1])
        {
            par[p1] = par[p2];
            size[p2] += size[p1];
            maxx = max(maxx, size[p2]);
        }
        --components;
    }

    int getMax()
    {
        return maxx;
    }

    int getComponents()
    {
        return components;
    }

};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    UF uf(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (uf.find(a) != uf.find(b))
        {
            uf.unionn(a, b);
        }
        cout << uf.getComponents() << ' ' << uf.getMax() << '\n';
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
