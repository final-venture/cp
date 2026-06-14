#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N;
    cin >> N;
    vector<int> a(3 * N);
    for (int i = 0; i < 3 * N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ret = 0;
    int cnt = 0;
    // for (auto x : a) {
    //     cerr << x << ' ';
    // }
    // cerr << '\n';
    for (int i = 3 * N - 2; i >= 0; i -= 2) {
        ret += a[i];
        // cout << i << '\n';
        ++cnt;
        if (cnt >= N) {
            break;
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
