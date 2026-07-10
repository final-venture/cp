#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXH = 1005;

void solve() {
    int M;
    cin >> M;
    vector<int> a(M + 1);
    for (int i = 1; i <= M; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(M + 1, vector<int>(MAXH, 1e9));
    vector<vector<char>> pred(M + 1, vector<char>(MAXH, '.'));
    dp[0][0] = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < MAXH; ++j) {
            // we look back at dp[i - 1][j - a[i]] and dp[i - 1][j + a[i]] if they are in bounds
            if (j - a[i] >= 0) {
                int newMax = max(j, dp[i - 1][j - a[i]]);
                if (newMax < dp[i][j]) {
                    dp[i][j] = newMax;
                    pred[i][j] = 'U';
                }
            }

            if (j + a[i] < MAXH) {
                int newMax = max(j, dp[i - 1][j + a[i]]);
                if (newMax < dp[i][j]) {
                    dp[i][j] = newMax;
                    pred[i][j] = 'D';
                }
            }
        }
    }

    // for (int i = 0; i <= M; ++i) {
    //     for (int j = 0; j < 25; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for (int i = 0; i <= M; ++i) {
    //     for (int j = 0; j < 25; ++j) {
    //         cout << pred[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    if (dp[M][0] == 1e9) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    int curr = 0;
    string ret;
    for (int i = M; i > 0; --i) {
        ret.push_back(pred[i][curr]);
        if (pred[i][curr] == 'U') {
            curr -= a[i];
        } else {
            curr += a[i];
        }
    }
    reverse(ret.begin(), ret.end());

    cout << ret << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
