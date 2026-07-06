#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int t, p;
    cin >> t >> p;
    vector<double> s(t);
    for (int i = 1; i <= t - 1; ++i) {
        cin >> s[i];
    }
    vector<double> d(p + 1);
    for (int i = 1; i <= p; ++i) {
        cin >> d[i];
    }
    vector<vector<char>> c(t + 1, vector<char>(p + 1));
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= p; ++j) {
            cin >> c[i][j];
        }
    }

    // compute probability of losing (or tying) for each team
    // dp[i][j] is the probability of getting j questions right for the first i questions.
    int yourCorrect = 0;
    for (int j = 1; j <= p; ++j) {
        yourCorrect += (c[t][j] == 'X');
    }

    vector<double> probLosing(t, 0);
    for (int team = 1; team <= t - 1; ++team) {
        vector<vector<double>> dp(p + 1, vector<double>(p + 1, 0));
        dp[0][0] = 1.0;
        for (int i = 1; i <= p; ++i) {
            double prob;
            if (c[team][i] == '?') {
                prob = s[team] * d[i];
            } else if (c[team][i] == 'X') {
                prob = 1;
            } else {
                prob = 0;
            }
            for (int j = 0; j <= p; ++j) {
                dp[i][j] = dp[i - 1][j] * (1.0 - prob);
                if (j > 0) {
                    dp[i][j] += dp[i - 1][j - 1] * prob;
                }
            }
        }
        for (int j = 0; j <= yourCorrect; ++j) {
            probLosing[team] += dp[p][j];
        }
    }

    double ret = 1;
    for (int i = 1; i <= t - 1; ++i) {
        ret *= probLosing[i];
    }
    cout << ret << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(8);
    solve();
    return 0;
}
