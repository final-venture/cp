#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
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

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            adj[i][j] = adj[j][i] = 1e15;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = c;
    }

    for (int via = 1; via <= n; ++via)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
            }
        }
    }

    while (q--)
    {
        int qa, qb;
        cin >> qa >> qb;
        if (adj[qa][qb] == 1e15)
            adj[qa][qb] = -1;
        cout << adj[qa][qb] << '\n';
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
