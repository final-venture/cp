#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> pfx(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pfx[i] = pfx[i - 1] + a[i];
    }

    // delta = (r^2 + r - pfx[r]) - (l^2 - l - pfx[l - 1])
    int max_delta = 0;
    int min_term2 = 0;
    for (int r = 1; r <= n; ++r) {
        int term1 = r*r + r - pfx[r];
        min_term2 = min(min_term2, r*r - r - pfx[r - 1]);
        max_delta = max(max_delta, term1 - min_term2);
    }
    cout << pfx[n] + max_delta << '\n';
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
