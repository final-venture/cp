#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    if (p >= q) {
        swap(p, q);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        b[i] = (a[i] % q) % p;
        c[i] = a[i] % p;
    }
    vector<int> pfx_b(n + 1, 0);
    vector<int> pfx_c(n + 1, 0);
    vector<int> pfx_minbc(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pfx_b[i] = pfx_b[i - 1] + b[i - 1];
        pfx_c[i] = pfx_c[i - 1] + c[i - 1];
        pfx_minbc[i] = pfx_minbc[i - 1] + min(b[i - 1], c[i - 1]);
    }

    int ret = 2e18;
    for (int i = k - 1; i < n; ++i) {
        int ed = i;
        int st = ed - k + 1;

        int sum_in_win = min(pfx_b[ed + 1] - pfx_b[st], pfx_c[ed + 1] - pfx_c[st]);
        int sum_outside = pfx_minbc[n] - (pfx_minbc[ed + 1] - pfx_minbc[st]);
        ret = min(ret, sum_in_win + sum_outside);
    }
    cout << ret << '\n';
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
