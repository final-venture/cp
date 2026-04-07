#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int p, q;
    cin >> p >> q;
    int x = 3*p - 2*q;
    if (x >= 0 && x < p && x < q) {
        cout << "Bob" << '\n';
        return;
    }
    cout << "Alice" << '\n';
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
