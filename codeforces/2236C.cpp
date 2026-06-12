#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    // enforce a >= b
    int a, b, x;
    cin >> a >> b >> x;
    if (a < b) {
        swap(a, b);
    }

    int add1 = 0;
    while (abs(a/x - b) < abs(a - b)) {
        a /= x;
        ++add1;
    }
    int best = add1 + abs(a - b);
    int add2 = 0;
    int A = a, B = b;
    while (A > 0 || B > 0) {
        if (A > 0) {
            A /= x;
            ++add2;
        }
        best = min(best, add1 + add2 + abs(A - B));
        if (B > 0) {
            B /= x;
            ++add2;
        }
        best = min(best, add1 + add2 + abs(A - B));
    }

    add2 = 0;
    A = a; B = b;
    while (A > 0 || B > 0) {
        if (B > 0) {
            B /= x;
            ++add2;
        }
        best = min(best, add1 + add2 + abs(A - B));
        
        if (A > 0) {
            A /= x;
            ++add2;
        }
        best = min(best, add1 + add2 + abs(A - B));
    }
    cout << best << '\n';
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
