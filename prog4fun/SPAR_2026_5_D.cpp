#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> sfx(n + 2);
    sfx[n + 1] = 0;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 0; --i) {
        sfx[i] = sfx[i + 1] + (1LL << i) * (1LL << i) * a[i];
    }
    int totalArea = sfx[0];

    // cout << totalArea << '\n';

    for (int h = 1; h * h <= totalArea; ++h) {
        if (totalArea % h != 0) {
            continue;
        }
        int w = totalArea / h;

        int ok = 1;
        for (int i = n; i >= 0; --i) {
            int roundedH = h - (h % (1 << i));
            int roundedW = w - (w % (1 << i));
            int roundedArea = roundedH * roundedW;
            if (sfx[i] > roundedArea) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << h << ' ' << w << '\n';
            return;
        }
    }
    cout << "impossible" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
