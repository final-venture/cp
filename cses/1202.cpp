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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> dp(n + 1, 0);
    vector<int> dists(n + 1, 1e15);
    vector<int> minn(n + 1, 1e6);
    vector<int> maxx(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dp[1] = 1;
    minn[1] = 0;
    while (!pq.empty())
    {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dist > dists[node]) continue;
        for (auto [neiDist, neiNode] : adj[node])
        {
            int newDist = dist + neiDist;
            if (newDist < dists[neiNode])
            {
                dists[neiNode] = newDist;
                dp[neiNode] = dp[node]; dp[neiNode] %= MOD;
                minn[neiNode] = 1 + minn[node];
                maxx[neiNode] = 1 + maxx[node];
                pq.push({newDist, neiNode});
            }
            else if (newDist == dists[neiNode])
            {
                dp[neiNode] += dp[node]; dp[neiNode] %= MOD;
                minn[neiNode] = min(minn[neiNode], 1 + minn[node]);
                maxx[neiNode] = max(maxx[neiNode], 1 + maxx[node]);
            }
        }
    }
    cout << dists[n] << ' ' << dp[n] << ' ' << minn[n] << ' ' << maxx[n];
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
