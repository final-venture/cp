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
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; ++j)
    {
        dp[0][j] = j;
    }
    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= m; ++j)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }
    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= m; ++j)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] << '\n';
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
