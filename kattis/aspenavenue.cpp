#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9
#define double long double

void solve() {
    int N;
    cin >> N;
    int L, W;
    cin >> L >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<vector<double>> dp(N / 2 + 1, vector<double>(N / 2 + 1, 1e18));
    vector<double> t(N / 2);
    t[0] = 0;
    double step = L * 1.0 / (N / 2 - 1);
    for (int i = 1; i < N / 2; ++i) {
        t[i] = t[i - 1] + step;
    }

    // for (auto x : t) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    dp[0][0] = 0;
    for (int i = 0; i <= N / 2; ++i) {
        for (int j = 0; j <= N / 2; ++j) {
            int pos = i + j;
            if (i + 1 <= N / 2) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + abs(a[pos] - t[i]));
            }
            if (j + 1 <= N / 2) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + sqrtl((a[pos] - t[j]) * (a[pos] - t[j]) + W * W));
            }
        }
    }

    // for (int i = 0; i <= N / 2; ++i) {
    //     for (int j = 0; j <= N / 2; ++j) {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << '\n';
    // }

    cout << dp[N / 2][N / 2] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    solve();
    return 0;
}
