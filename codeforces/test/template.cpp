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

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 1 + a[0] << '\n';
        return;
    }
    vector<pair<int, int>> dp(n, {0, 0});
    dp[n - 1] = {1, a[n - 1]};
    dp[n - 2] = {1, a[n - 2]};
    for (int i = n - 3; i >= 0; --i)
    {
        for (int j = i + 2; j < n; ++j)
        {
            if (dp[j].first + 1 + dp[j].second > dp[j].first + 1 + a[i])
            {
                dp[i] = {dp[j].first + 1, dp[j].second};
            }
            else
            {
                dp[i] = {dp[j].first + 1, a[i]};
            }
        }
    }
    for (auto& [x, y] : dp) cout << x << ' ' << y << '\n';
    for (int i = 0; i < n; ++i)
    {
        res = max(res, dp[i].first + dp[i].second);
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
