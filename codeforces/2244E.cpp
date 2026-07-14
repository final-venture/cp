#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> vio(n);
    vector<char> match{'0', '1'};
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != match[curr]) {
            vio[i] = 1;
        }
        else {
            vio[i] = 0;
        }
        curr++;
        curr %= 2;
    }

    // for (auto x : vio) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    vector<int> chg(n, 0);
    for (int i = 1; i < n; ++i) {
        chg[i] = chg[i - 1];
        if (vio[i - 1] != vio[i]) {
            chg[i] += 1;
        }
    }

    // for (auto x : chg) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        --r;
        int total = chg[r] - chg[l] + 1;
        int needed = total / 2;
        if (needed <= k) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
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
