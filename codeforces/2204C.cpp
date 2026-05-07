#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    // add how much they collect a + b + c
    // subtract (a and b)
    // subtract (b and c)
    // subtract (a and c)
    // add back (a and b and c)
    int col_a = m / a * 6;
    int col_b = m / b * 6;
    int col_c = m / c * 6;

    int col_ab = m / lcm(a, b) * 3;
    int col_ac = m / lcm(a, c) * 3;
    int col_bc = m / lcm(b, c) * 3;

    int col_abc = m / lcm(lcm(a, b), c) * 2; 

    int total_a = col_a - col_ab - col_ac + col_abc;
    int total_b = col_b - col_ab - col_bc + col_abc;
    int total_c = col_c - col_bc - col_ac + col_abc;

    cout << total_a << ' ' << total_b << ' ' << total_c << '\n';
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
