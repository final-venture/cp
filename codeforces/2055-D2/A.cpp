#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int diff = abs(a - b);
    if (diff & 1)
    {
        cout << "NO" << '\n';
        return;
    }
    else
    {
        cout << "YES" << '\n';
        return;
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
