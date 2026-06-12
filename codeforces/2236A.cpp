#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    int minn = 1e9;
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        minn = min(x, minn);
        maxx = max(maxx, x);
    }
    cout << (maxx - minn + 1) << '\n';
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
