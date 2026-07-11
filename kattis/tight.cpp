#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int k, n;
const int MAXN = 105;
const int MAXD = 12;
double dp[MAXN][MAXD];

double dfs(int idx, int dig) {
    if (idx >= n - 1) {
        return 1;
    }
    if (dp[idx][dig] > -0.9) {
        return dp[idx][dig];
    }
    double ret = 0;
    for (int del = -1; del <= 1; ++del) {
        int newDig = dig + del;
        if (0 <= newDig && newDig <= k) {
            ret += dfs(idx + 1, newDig);
        }
    }
    return dp[idx][dig] = ret;
}

void solve() {
    double ret = 0;
    for (int d = 0; d <= k; ++d) {
        ret += dfs(0, d);
    }

    double all = 1;
    for (int i = 0; i < n; ++i) {
        all *= (k + 1);
    }

    // cout << ret << '\n';
    cout << (ret / all) * 100 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(9);
    while (cin >> k >> n) {
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXD; ++j) {
                dp[i][j] = -1.0;
            }
        }
        solve();
    }
    return 0;
}
