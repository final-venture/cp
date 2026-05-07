#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    int max_height = d / m + 1;
    if (n % max_height == 0) {
        cout << n / max_height << '\n';
    }
    else {
        cout << n / max_height + 1 << '\n';
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
