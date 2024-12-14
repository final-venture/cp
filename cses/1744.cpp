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
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            for (int h = 1; h <= i - 1; ++h)
            {
                dp[i][j] = min(dp[i][j], dp[i - h][j] + dp[h][j] + 1);
            }
            for (int v = 1; v <= j - 1; ++v)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - v] + dp[i][v] + 1);
            }
        }
    }
    cout << dp[a][b] << '\n';
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
