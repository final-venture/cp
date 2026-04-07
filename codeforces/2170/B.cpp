#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int nonzero_cnt = 0;
    int summ = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] > 0) {
            ++nonzero_cnt;
            summ += b[i];
        }
    }

    int ret = 0;
    for (int i = 0; i <= nonzero_cnt; ++i) {
        if (summ - i < n - 1) {
            break;
        }
        ret = max(ret, i);
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
