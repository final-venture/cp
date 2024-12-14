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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<pair<int, int>> dp((1 << n), {1e8, 1e8});
    dp[0] = {1, 0};
    for (int i = 1; i < (1 << n); ++i)
    {
        for (int bit = 0; bit < n; ++bit)
        {
            if ((1 << bit) & i)
            {
                int trips = dp[i ^ (1 << bit)].first;
                int space = dp[i ^ (1 << bit)].second;
                if (space + a[bit] <= x)
                {
                    dp[i] = min(dp[i], {trips, space + a[bit]});
                }
                else
                {
                    dp[i] = min(dp[i], {trips + 1, a[bit]});
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].first << '\n';
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
