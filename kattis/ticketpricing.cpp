#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int NINF = -1e9;

void solve() {
    int N, W;
    cin >> N >> W;
    vector<vector<pair<int, int>>> prices(W + 1);
    for (int i = 0; i <= W; ++i) {
        int K;
        cin >> K;
        prices[i].resize(K);
        for (int j = 0; j < K; ++j) {
            cin >> prices[i][j].first;
        }
        for (int j = 0; j < K; ++j) {
            cin >> prices[i][j].second;
        }
    }

    // assume the flight is on week W + 1, then:
    // dp[i][j] stores the max profit if we start selling from i'th week
    // and we have an available capacity of j passengers on the flight
    vector<vector<int>> dp(W + 2, vector<int>(N + 1, NINF));
    for (int j = 0; j <= N; ++j) {
        dp[W + 1][j] = 0;
    }

    int best = 1e9;
    for (int i = W; i >= 0; --i) {
        int K = prices[i].size();

        for (int j = N; j >= 0; --j) {
            for (int k = 0; k < K; ++k) {
                int sold = min(j, prices[i][k].second);
                int revenue = (sold * prices[i][k].first) + dp[i + 1][j - sold];
                if (revenue > dp[i][j]) {
                    dp[i][j] = revenue;
                    if (i == 0 && j == N) {
                        best = prices[i][k].first;
                    }
                } else if (i == 0 && j == N && revenue == dp[i][j]) {
                    best = min(best, prices[i][k].first);
                }
            }
        }
    }

    cout << dp[0][N] << '\n';
    cout << best << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
