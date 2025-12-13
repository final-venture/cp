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
    vector<int> rank;
    vector<int> par;
    UF(int sz)
    {
        rank = vector<int>(sz, 1);
        par = vector<int>(sz);
        for (int i = 0; i < sz; ++i)
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
        int p1 = find(x1);
        int p2 = find(x2);
        if (rank[p1] > rank[p2])
        {
            par[p2] = par[p1];
            rank[p1] += rank[p2];
        }
        else
        {
            par[p1] = par[p2];
            rank[p2] += rank[p1];
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    UF dsu = UF(n + 1);
    vector<vector<int>> moves(n + 1, vector<int>(11, 0));
    for (int i = 0; i < m; ++i)
    {
        int a, d, k;
        cin >> a >> d >> k;
        moves[a][d] = max(moves[a][d], k);
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < 11; ++j)
        {
            int movecnt = moves[i][j];
            int pos = i;
            while (movecnt && pos + j < n + 1)
            {
                --movecnt;
                dsu.unionn(pos, pos + j);
                moves[pos + j][j] = max(moves[pos + j][j], movecnt);
                moves[pos][j] = 0;
                pos += j;
                movecnt = max(movecnt, moves[pos][j]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        if (dsu.find(i) == i)
        {
            ++res;
        }
    }
    cout << res << '\n';
}

signed main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
