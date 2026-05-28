#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// The monthly interest is rounded to the nearest cent (rounding up 0.5
// cents and above) in the calculations.

// B = initial outstanding balance
// M = monthly payment
// R = APR (in percentage)

void solve()
{
    long double R_, B_, M_;
    cin >> R_ >> B_ >> M_;
    
    int R, B, M;
    R = round(R_ * 100);
    B = round(B_ * 100);
    M = round(M_ * 100);

    for (int i = 1; i <= 1200; ++i) {
        int interest = (B * R + 5000) / 10000;
        B = B + interest - M;

        if (B <= 0) {
            cout << i << '\n';
            return;
        }
    }
    cout << "impossible" << '\n';
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
