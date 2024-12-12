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
    // dp[i] is the min coins to reach i amount
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> a[i];
    }
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < x + 1; ++j)
        {
            if (j >= a[i])
            {
                dp[j] = min(dp[j - a[i]] + 1, dp[j]);
            }
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << '\n';
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
