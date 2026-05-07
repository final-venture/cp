#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define MOD 998244353
#define int ll

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = (arr[1] == 0 ? 1 : 0);
    for (int i = 2; i <= n; ++i)
    {
        if (arr[i] == arr[i - 2] + 1)
        {
            dp[i] += dp[i - 2];
            dp[i] %= MOD;
        }
        if (arr[i] == arr[i - 1])
        {
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
        }
    }
    cout << (dp[n - 1] + dp[n]) % MOD << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
