#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;

    const int numCnt = 1e12;

    if (y == 1) {
        cout << -1 << '\n';
        return;
    }

    int kk = k;

    // split the numbers into groups of y elements
    // then use the fact that a_(k-1) = q * y + r
    while (x--) {
        // q is the number of groups with y elements 
        // that had a number removed, hence (y-1) remaining
        int q = (kk - 1) / (y - 1);

        // r is the offset within the current group
        int r = (kk - 1) % (y - 1) + 1;

        int newK = q * y + r;
        kk = newK;
        if (kk > numCnt) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << kk << '\n';
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
