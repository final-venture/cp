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
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = a[i]; k < n && k <= a[i] * a[i]; k += a[i]) {
            int j = i + k;
            if (j < n && a[i] * a[j] == k) {
                ++ret;
            }
            j = i - k;
            if (j >= 0 && a[i] * a[j] == k) {
                if (a[i] != a[j]) {
                    ++ret;
                }
            }
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