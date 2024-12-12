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

// dp[i] is the number of ways to make amount i
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> a[i];
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < x + 1; ++j)
        {
            if (j >= a[i])
            {
                dp[j] += dp[j - a[i]];
                dp[j] %= MOD;
            }
        }
        // for (int x : dp) cout << x << ' ';
        //     cout << '\n';
    }

    cout << dp[x] << '\n';
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
