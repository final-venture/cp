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
    
    vector<int> dp(k + 1, INF);
    dp[0] = 0;

    int lzy = 0;
    int currMin = INF;
    for (int i = 1; i <= n; ++i) {
        // true value of each value in dp is dp[i] + lzy.

        int lzyUpdate = (a[i] != a[i - 1]) ? cold[a[i]] : hot[a[i]];
        int cold2 = currMin + lzy + cold[a[i]];
        int hot2 = dp[a[i]] + hot[a[i]] + lzy;

        lzy += lzyUpdate;

        if (cold2 < dp[a[i - 1]] + lzy) {
            dp[a[i - 1]] = cold2 - lzy;
        }
        if (hot2 < dp[a[i - 1]] + lzy) {
            dp[a[i - 1]] = hot2 - lzy;
        }

        currMin = min(currMin, dp[a[i - 1]]);
    }

    int ret = *min_element(dp.begin(), dp.end()) + lzy;
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
