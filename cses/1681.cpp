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

const int MOD = 1000000007;

int n, m;
vector<int> seen;
// actually don't need this seen array,
// because it's a DAG.
// We only need to see if 1 is locked/omitted or not. Nothing else.
vector<vector<int>> adj;
vector<int> dp;
vector<int> indeg;

void topo(queue<int>& q)
{
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (seen[node]) continue;
        seen[node] = 1;
        for (int nei : adj[node])
        {
            dp[nei] += dp[node];
            dp[nei] %= MOD;
            --indeg[nei];
            if (!indeg[nei])
            {
                q.push(nei);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    seen.resize(n + 1, 0);
    dp.resize(n + 1, 0);
    indeg.resize(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        ++indeg[b];
    }
    queue<int> q;
    seen[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!indeg[i]) q.push(i);
    }
    topo(q);
    seen[1] = 0;
    dp[1] = 1;
    if (!indeg[1]) q.push(1);
    topo(q);
    cout << dp[n] << '\n';
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
