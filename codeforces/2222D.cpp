#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> pfx(n);
    for (int i = 0; i < n; ++i) {
        pfx[i] = {0, i};
    }
    for (int i = 1; i < n; ++i) {
        pfx[i].first = pfx[i - 1].first + a[i - 1];
    }
    sort(pfx.begin(), pfx.end(), greater<>());
    vector<int> ret(n);
    int curr = 1;
    for (int i = 0; i < n; ++i) {
        ret[pfx[i].second] = curr++;
    }
    for (int i = 0; i < n; ++i) {
        cout << ret[i] << ' ';
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
