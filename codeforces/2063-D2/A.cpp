#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int l, r;
    cin >> l >> r;
    if (l == 1 && r == 1)
    {
        cout << 1 << '\n';
        return;
    }
    cout << r - l << '\n';
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
