#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, a;
    cin >> n >> a;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> delta_a(n);
    for (int i = 0; i < n; ++i) {
        delta_a[i] = a - v[i];
    }

    int ret = -1;
    int best = -1;
    for (int diff = -1; diff <= 1; diff += 2) {
        int cand = 0;
        for (int i = 0; i < n; ++i) {
            if (abs(delta_a[i]) > abs(delta_a[i] + diff)) {
                ++cand;
            }
        }
        if (cand > best) {
            ret = a + diff;
            best = cand;
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
