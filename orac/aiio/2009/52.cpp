#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

vector<vector<int>> adj;
const int inf = 1e9;

void solve()
{
    int p, j;
    cin >> p >> j;
    int st_a, st_b;
    cin >> st_a >> st_b;
    adj.resize(p + 1);
    for (int i = 0; i < j; ++i)
    {
        int p1, p2;
        cin >> p1 >> p2;
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }
    vector<vector<int>> dp_a(2, vector<int>(p + 1, inf)); // dp[0][x] is even, dp[1][x] is odd
    vector<vector<int>> dp_b(2, vector<int>(p + 1, inf));
    queue<pair<int, pair<int, bool>>> q; // dist, node, isA
    q.push({0, {st_a, true}});
    q.push({0, {st_b, false}});
    while (!q.empty())
    {
        auto [dist, p] = q.front();
        auto &[node, isA] = p;
        int parity = (dist & 1);
        q.pop();

        if (isA && dp_a[parity][node] <= dist)
            continue;
        else if (!isA && dp_b[parity][node] <= dist)
            continue;

        if (isA)
        {
            dp_a[parity][node] = dist;
            if (dp_b[parity][node] != inf)
            {
                cout << max(dp_b[parity][node], dp_a[parity][node]) << ' ' << node;
                return;
            }
        }
        else
        {
            dp_b[parity][node] = dist;
            if (dp_a[parity][node] != inf)
            {
                cout << max(dp_b[parity][node], dp_a[parity][node]) << ' ' << node;
                return;
            }
        }

        for (int nei : adj[node])
        {
            q.push({dist + 1, {nei, isA}});
        }
    }

    cout << "Broken heart";
}

signed main()
{
#ifndef LOCAL
    freopen("frogsin.txt", "r", stdin);
    freopen("frogsout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
