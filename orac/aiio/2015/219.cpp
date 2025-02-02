#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

int n, k;
vector<int> dp;
vector<pair<int, pair<int, int>>> edges;

void solve()
{
    cin >> n >> k;
    dp.resize(k + 1, 0);
    edges.resize(n);
    for (int i = 0; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }
    for (int i = n - 1; i >= 0; --i)
    {
        auto [wt, p] = edges[i];
        auto &[u, v] = p;
        dp[u] = max(dp[u], dp[v] + wt);
    }
    int maxx = 0;
    int cnt = k;
    for (int i = 1; i <= k; ++i)
    {
        if (maxx < dp[i])
        {
            maxx = dp[i];
            cnt = 1;
        }
        else if (maxx == dp[i])
        {
            ++cnt;
        }
    }
    cout << maxx << '\n';
    cout << cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
