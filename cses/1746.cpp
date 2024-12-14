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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n + 1; ++i)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    // dp[i][j] is number of arrays from subarray [0, i] if a[i] has value j
    if (!a[0])
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[0][j] = 1;
        }
    }
    else
    {
        dp[0][a[0]] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        if (!a[i])
        {
            for (int j = 1; j <= m; ++j)
            {
                for (int k = -1; k <= 1; ++k)
                {
                    if (1 <= j + k && j + k <= m)
                    {
                        dp[i][j] += dp[i - 1][j + k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        else
        {
            int j = a[i];
            for (int k = -1; k <= 1; ++k)
            {
                if (1 <= j + k && j + k <= m)
                {
                    dp[i][j] += dp[i - 1][j + k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    int ret = 0;
    for (int j = 1; j <= m; ++j)
    {
        ret += dp[n - 1][j];
        ret %= MOD;
    }
    cout << ret << '\n';
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
