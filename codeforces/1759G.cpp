#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n / 2);
    vector<int> b(n);
    iota(b.begin(), b.end(), 1LL);
    set<int> p(b.begin(), b.end());
    for (int i = 0; i < n / 2; ++i) {
        cin >> a[i];
        b[i * 2 + 1] = a[i];
        p.erase(a[i]);
    }

    if (p.size() != n / 2) {
        cout << -1 << '\n';
        return;
    }

    for (int i = n / 2 - 1; i >= 0; --i) {
        auto it = p.lower_bound(a[i]);
        if (it == p.begin()) {
            cout << -1 << '\n';
            return;
        }
        --it;
        b[i * 2] = *it;
        p.erase(it);
    }
    for (auto x : b) {
        cout << x << ' ';
    }
    cout << '\n';
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
