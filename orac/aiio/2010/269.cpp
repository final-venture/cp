#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> wts(n + 1);
    vector<int> costs(n + 1);
    cin >> wts[1] >> costs[1];
    for (int i = 2; i <= n; ++i)
    {
        cin >> wts[i] >> costs[i];
        int par;
        cin >> par;
        wts[i] += wts[par];
        costs[i] += costs[par];
    }
    vector<int> dp(c + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = costs[i]; j <= c; ++j)
        {
            // cout << "?XD";
            dp[j] = max(dp[j - costs[i]] + wts[i], dp[j]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}

signed main()
{
#ifndef LOCAL
    freopen("clamin.txt", "r", stdin);
    freopen("clamout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
