#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

#define LOCAL

void init()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n, m, k, u;
unordered_map<int, vector<pair<int, int>>> adj;
unordered_map<int, vector<int>> trout;
vector<int> troutcnt(100005, 0);
vector<int> termcnt(100005, 0);
vector<int> travelled;
vector<int> dists;

int dfs(int node, int dist)
{
    int res = 0;
    travelled.pb(node); dists.pb(dist);
    for (auto& [to, distTo] : adj[node])
    {
        res += dfs(to, dist + distTo);
    }
    for (int td : trout[node])
    {
        ++res;
        int d = dist - td;
        int idx = lower_bound(all(dists), d) - dists.begin();
        ++termcnt[travelled[idx]];
    }
    troutcnt[node] = res;
    travelled.pop_back(); dists.pop_back();
    return res - termcnt[node];
}

void solve()
{
    cin >> n >> m >> k >> u;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
    }
    for (int i = 0; i < m; ++i)
    {
        int loc, dist;
        cin >> loc >> dist;
        trout[loc].pb(dist);
    }
    dfs(0, 0);
    for (int i = 0; i < k; ++i)
    {
        char cmd;
        int x, y;
        cin >> cmd >> x;
        if (cmd == 'D') y = 0 / 0;
        else
        {
            cout << troutcnt[x] << '\n';
        }
    }
}

signed main()
{
    init();
#ifdef LOCAL
    int t;
    cin >> t;
    while (t--)
#endif
        solve();
    return 0;
}
