#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define EPS 1e-9

const double MAXA = 1e18;

double d, s;
// check whether we need to increase a
bool check(double a) {
    double LHS = s;
    double RHS = a * coshl(d/(2*a)) - a;
    if (RHS - LHS > 0) {
        return true;
    }
    else {
        return false;
    }
}

void solve()
{
    cin >> d >> s;

    double l = 0, r = MAXA;
    // int its = 0;
    for (int i = 0; i < 100; ++i) {
        double m = (r + l) / 2;
        if (check(m)) {
            l = m;
        }
        else {
            r = m;
        }
        // cout << l << ' ' << r << '\n';
    }
    cout << fixed << setprecision(9);
    cout << (2*l * sinh(d/(2*l))) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
