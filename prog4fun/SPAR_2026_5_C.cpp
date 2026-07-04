#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int n, c, y;
    cin >> n >> c >> y;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    int modded = -1;
    for (int i = 1; i <= n; ++i) {
        if (i == c) {
            continue;
        }
        if (modded == -1) {
            modded = x[i] % (y + 1);
        } else if (modded != x[i] % (y + 1)) {
            cout << "impossible" << '\n';
            return;
        }
    }

    int K = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == c) {
            continue;
        }
        K = max(K, x[i]);
    }
    int summ = accumulate(x.begin() + 1, x.end(), 0LL);
    cout << K << ' ' << summ + K * (y - n + 1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
