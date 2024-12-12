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
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        int tmp = i;
        while (tmp)
        {
            int d = tmp % 10;
            if (i - d >= 0)
            {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
            tmp /= 10;
            // cout << tmp << '\n';
        }
    }
    // for (int x : dp) cout << x << ' ';
    // cout << '\n';
    cout << dp[n] << '\n';
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
