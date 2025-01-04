#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9
#define int ll

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
    int n, w;
    cin >> n >> w;
    vector<int> wts(n + 1);
    vector<int> vals(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> wts[i] >> vals[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            if (j - wts[i] >= 0)
                dp[i][j] = dp[i - 1][j - wts[i]] + vals[i];
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    ll ret = 0;
    for (int j = 0; j <= w; ++j)
    {
        ret = max(ret, dp[n][j]);
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
