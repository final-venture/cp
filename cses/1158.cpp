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
    vector<int> h(n); // price
    vector<int> s(n); // pgs
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    // dp[i][j] is max pages u can buy considering up to idx i inclusive, with amount j
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < x + 1; ++j)
        {
            int pgs = s[i - 1];
            int cost = h[i - 1];

            int take = 0;
            int notTake = dp[i - 1][j]; // do we need max here?
            if (j - cost >= 0)
            {
                take = dp[i - 1][j - cost] + pgs;
            }
            dp[i][j] = max(take, notTake);
        }
    }
    cout << dp[n][x] << '\n';
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
