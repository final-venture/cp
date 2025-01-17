#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

int s, n, t, h;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> dp;
vector<int> songs;

void solve()
{
    cin >> s;
    songs.resize(s + 1);
    for (int i = 1; i <= s; ++i)
    {
        cin >> songs[i];
    }
    cin >> n >> h;
    cin >> t;
    adj.resize(n + 1);
    for (int i = 0; i < t; ++i)
    {
        int u, v, m;
        cin >> u >> v >> m;
        adj[u].push_back({m, v});
        adj[v].push_back({m, u});
    }
    // dp[i][j] is min eggs at node i when we have played up to the j-th song.
    dp.resize(n + 1, vector<int>(s + 1, 1e9));
    dp[h][0] = 0;
    for (int j = 1; j <= s; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (dp[i][j - 1] == 1e9)
                continue;
            for (auto &[neiSong, neiNode] : adj[i])
            {
                int add = (neiSong != songs[j]);
                // cout << neiSong << ' ' << songs[j + 1] << '\n';
                dp[neiNode][j] = min(dp[neiNode][j], dp[i][j - 1] + add);
            }
        }
    }
    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= s; ++j)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[h][s];
}

signed main()
{
#ifndef LOCAL
    freopen("drivein.txt", "r", stdin);
    freopen("driveout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
