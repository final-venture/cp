#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    b.push_back(0);

    sort(b.begin(), b.end(), greater<>());
    vector<int> pfx(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pfx[i] = pfx[i - 1] + a[i - 1];
    }

    int invert = 0;
    int benefit = 0;
    for (int i = 1; i <= m; ++i) {
        int mul = (invert) ? -1 : 1;
        int rangeSum = (pfx[b[i - 1]] - pfx[b[i]]) * mul;
        if (rangeSum < 0) {
            benefit -= 2 * pfx[b[i - 1]] * mul;
            invert ^= 1;
        }
    }

    cout << pfx[n] + benefit << '\n';
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
