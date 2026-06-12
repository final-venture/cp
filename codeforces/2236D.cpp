#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// sort the array
// find the "buckets" and go to the end of them, if there exists one that has even parity of count, return yes
// 1, 1, 1, 3

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> cnt {0};
    vector<int> ok {0};
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] == a[i - 1]) {
            ++cnt.back();
        }
        else if (i > 0 && a[i] - a[i - 1] <= k) {
            cnt.back() = 1;
            ok.back() = 1;
        }
        else {
            cnt.push_back(1);
            ok.push_back(0);
        }
        // for (auto x : cnt) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
    }

    int sz = cnt.size();
    for (int i = 0; i < sz; ++i) {
        if (ok[i] || (cnt[i] % 2 == 0)) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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
