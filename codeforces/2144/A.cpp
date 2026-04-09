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
    int summ = accumulate(a.begin(), a.end(), 0LL);
    if (summ % 3 == 0) {
        cout << 1 << ' ' << 2 << '\n';
    }
    else {
        cout << 0 << ' ' << 0 << '\n';
    }
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
