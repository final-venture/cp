#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define MOD 1000000007

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

vector<int> seen;
vector<int> vals;
unordered_map<int, vector<int>> adj;
int d;

ll dfs(int node, int par)
{
    ll dfsRes = 1;
    seen[node] = 1;
    for (int neiNode : adj[node])
    {
        int neiVal = vals[neiNode];
        if (!seen[neiNode] && ( (neiVal > vals[par] && neiVal - vals[par] <= d) ||
                                (neiVal == vals[par] && neiNode > par)))
        {
            dfsRes *= (dfs(neiNode, par) + 1ll);
            dfsRes %= MOD;
        }
    }
    return dfsRes;
}

void solve()
{
    int n;
    cin >> d >> n;
    vals = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vals[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        seen = vector<int>(n, 0);
        res += dfs(i, i);
    }
    cout << res % MOD << '\n';
}

int main()
{
    init();
    int t = 1;
    while (t--)
        solve();
    return 0;
}
