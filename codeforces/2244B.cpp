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
    int thresh = n * (n + 1) / 2;
    int summ = accumulate(a.begin(), a.end(), 0LL);
    if (summ < thresh) {
        cout << "NO" << '\n';
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] < i + 1) {
            cout << "NO" << '\n';
            return;
        }
        if (i < n - 1) {
            a[i + 1] += (a[i] - (i + 1));
        }
    }

    cout << "YES" << '\n';
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
