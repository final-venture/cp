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
    int min_odd = 1e9, min_even = 1e9;
    int max_odd = 0, max_even = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] & 1) {
            max_odd = max(max_odd, a[i]);
            min_odd = min(min_odd, a[i]);
        }
        else {
            min_even = min(min_even, a[i]);
            max_even = max(max_even, a[i]);
        }
    }
    int max_so_far_odd = 0, max_so_far_even = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] & 1) {
            // odd, so we need an even dummy which is bigger than max so far or smaller than a[i]
            if (max_so_far_odd > a[i]) {
                if (max_even <= max_so_far_odd && min_even >= a[i]) {
                cout << "NO" << '\n';
                return;
            }
            }            
            max_so_far_odd = max(max_so_far_odd, a[i]);
        }
        else {
            // even
            if (max_so_far_even > a[i]) {
                if (max_odd <= max_so_far_even && min_odd >= a[i]) {
                    cout << "NO" << '\n';
                    return;
                }
            }
            max_so_far_even = max(max_so_far_even, a[i]);
        }
    }
    cout << "YES" << '\n';
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
