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
    vector<vector<int>> dp(a, vector<int>(b, 0));
    for (int i = 1; i < a; ++i)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j < b; ++j)
    {
        dp[0][j] = j;
    }
    for (int i = 0; i < a; ++i)
    {
        dp[i][i] = 0;
    }
    for (int k = 1; k < min(a, b); ++k)
    {
        for (int i = k + 1; i < a; ++i)
        {
            cout << i - k - 1 << endl;
            dp[i][k] += (1 + dp[i - k - 1][k]);
        }
        for (int j = k + 1; j < b; ++j)
        {
            cout << j - k - 1 << endl;
            dp[k][j] += (1 + dp[k][j - k - 1]);
        }
    }
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << dp[a - 1][b - 1] << '\n';
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
