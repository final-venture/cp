#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int s, p, m, n;
    cin >> s >> p >> m >> n;
    vector<int> dp(n + 1);
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1] + s;

        int nxt = lower_bound(t.begin(), t.end(), t[i] + m) - t.begin();
        nxt = min(nxt, n);
        dp[i] = min(dp[i], p + dp[nxt]);
    }
    cout << dp[0] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
