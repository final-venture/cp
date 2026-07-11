#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(2001, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 2000; j >= a[i]; --j) {
            dp[j] |= dp[j - a[i]];
        }
    }

    int best = 0;
    for (int j = 0; j < 2001; ++j) {
        if (!dp[j]) {
            continue;
        }
        int currDist = abs(best - 1000);
        int newDist = abs(j - 1000);
        if (newDist < currDist) {
            best = j;
        } else if (newDist == currDist) {
            best = max(best, j);
        }
    }

    cout << best << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
