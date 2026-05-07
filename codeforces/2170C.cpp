#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> q(n), r(n);
    multiset<int> q_s, r_s;
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        q_s.insert(q[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        r_s.insert(r[i]);
    }

    int ret = 0;
    while (!q_s.empty() && !r_s.empty()) {
        int r_lo = *r_s.begin();
        int q_hi = (k - r_lo) / (r_lo + 1);

        // for (auto x : q_s) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        // for (auto x : r_s) {
        //     cout << x << ' ';
        // }
        // cout << '\n';

        auto it = q_s.upper_bound(q_hi);
        if (it == q_s.begin()) {
            break;
        }
        --it;
        q_s.erase(it);
        r_s.erase(r_s.begin());
        ++ret;
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
