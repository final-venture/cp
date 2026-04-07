#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    int comb_jk = 0;
    for (int k_start = 0; k_start < n; ++k_start) {
        int ok = 1;
        for (int it = 0; it < n; ++it) {
            // 'it' is the index of b
            // cout << b[it] << ' ' << c[(k_start + it) % n] << '\n';
            if (b[it] >= c[(k_start + it) % n]) {
                ok = 0;
            }
        }
        if (ok) {
            comb_jk += n;
        }
    }

    int comb_ij = 0;
    for (int j_start = 0; j_start < n; ++j_start) {
        int ok = 1;
        for (int it = 0; it < n; ++it) {
            // 'it' is the index of a
            if (a[it] >= b[(j_start + it) % n]) {
                ok = 0;
            }
        }
        if (ok) {
            comb_ij += comb_jk;
        }
    }
    cout << comb_ij << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
