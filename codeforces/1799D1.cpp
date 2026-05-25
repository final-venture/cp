#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int INF = 1e17;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> cold(k + 1);
    vector<int> hot(k + 1);
    a[0] = 0;
    cold[0] = INF;
    hot[0] = INF;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> cold[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> hot[i];
    }

    // fix the two CPUs in some order.
    // dp[i][j] stores min time to run programs up to a[i], where
    // the program last run on CPU #1 is the program on index a[i - 1],
    // and the program ran on CPU #2 is a[j].

    // for in in the range [1..n]:
    //  for j in the range [0..k]:

    // Two choices we can make:
    // 1. run program a[i] on CPU #1:
    //  dp[i][j] = dp[i - 1][j] + cold[a[i]] if a[i] != a[i - 1], else dp[i - 1][j] + hot[a[i]] if a[i] == a[i - 1].
    // 2. run program a[i] on CPU #2 (swap them around):
    //  dp[i][a[i - 1]] = dp[i - 1][a[i]] + hot[a[i]]
    
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int j = 0; j <= k; ++j) {
        if (j == 0) {
            dp[0][j] = 0;
        }
        else {
            dp[0][j] = INF;
        }
    }
    for (int i = 1; i <= n; ++i) {
        // run it on core 1
        for (int j = 0; j <= k; ++j) {
            if (a[i] != a[i - 1]) {
                dp[i][j] = dp[i - 1][j] + cold[a[i]];
            }
            else {
                dp[i][j] = dp[i - 1][j] + hot[a[i]];
            }
        }
        for (int j = 0; j <= k; ++j) {
            if (j == a[i]) {
                dp[i][a[i - 1]] = min(dp[i][a[i - 1]], dp[i - 1][j] + hot[a[i]]);
            }
            else {
                dp[i][a[i - 1]] = min(dp[i][a[i - 1]], dp[i - 1][j] + cold[a[i]]);
            }
        }
        // run it on core 2, we swap core 1 and 2 so that the one running on core 1 is always a[i]
        // so our last run on core 2 will become a[i - 1]
        // and we can only get the hot value if previously a[i] was run as well on core 2
        // otherwise, we have to take the cold value
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 0; j <= k; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ret = *min_element(dp[n].begin(), dp[n].end());
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
