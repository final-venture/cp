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
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        if (grid[i][0] == '*') break;
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; ++j)
    {
        if (grid[0][j] == '*') break;
        dp[0][j] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (grid[i][j] == '*') continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[n - 1][n - 1] << '\n';
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
