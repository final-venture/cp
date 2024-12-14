#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
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

void solve()
{
    int t;
    cin >> t;
    vector<int> qs(t);
    for (int i = 0; i < t; ++i)
    {
        cin >> qs[i];
    }
    int maxx = *max_element(all(qs));
    // dp[i][j] is number of ways to build tower of height i, in the j-th situation.
    // "situation": when j = 0: one big open pipe (width 2), j = 1: two open pipes (width 1)
    vector<vector<ll>> dp(maxx + 1, vector<ll>(2, 0));
    dp[1][0] = 1; dp[1][1] = 1;
    for (int i = 2; i <= maxx; ++i)
    {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][0] * 2;
        dp[i][0] %= MOD;

        dp[i][1] = dp[i - 1][1] * 4 + dp[i - 1][0];
        dp[i][1] %= MOD;
    }
    for (int i = 0; i < t; ++i)
    {
        int q = qs[i];
        cout << (dp[q][0] + dp[q][1]) % MOD << '\n';
    }
}

signed main()
{
    init();
    solve();
    return 0;
}
