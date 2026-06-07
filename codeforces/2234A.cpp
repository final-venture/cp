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
    
    sort(a.begin(), a.end(), greater<>());
    if (n == 2) {
        cout << a[0] << ' ' << a[1] << '\n';
        return;
    }
    for (int i = 2; i < n; ++i) {
        if ((a[i - 2] % a[i - 1]) != a[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << a[0] << ' ' << a[1] << '\n';
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
