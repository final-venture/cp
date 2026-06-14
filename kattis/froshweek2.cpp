#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> t(n), l(m);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> l[i];
    }

    sort(t.begin(), t.end(), greater<>());
    sort(l.begin(), l.end(), greater<>());

    int i = 0;
    int j = 0;
    int ret = 0;
    while (i < n && j < m) {
        while (i < n && t[i] > l[j]) {
            ++i;
        }
        if (i < n) {
            ++ret;
            ++j;
            ++i;
        }
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
