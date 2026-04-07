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
    int ret = 1;
    int mini = a[0];
    for (int i = 1; i < n; ++i) {
        if (mini + 1 <= a[i] && a[i] <= a[i - 1] + 1) {
            continue;
        }
        else {
            mini = a[i];
            ++ret;
        }
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
