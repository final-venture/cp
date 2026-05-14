#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<int> num2Hash;
mt19937_64 rng(time(NULL));

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (num2Hash[a[i]] == -1) {
            num2Hash[a[i]] = rng();
        }
    }

    vector<int> pfx(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pfx[i] = pfx[i - 1] ^ num2Hash[a[i - 1]];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (pfx[r] == pfx[l - 1]) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    num2Hash.assign(1e6 + 2, -1);
    while (t--)
        solve();
    return 0;
}
