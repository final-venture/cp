#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// x_2 - x_1 = c
// x_2 + x_1 = D / c;
// 2*x_2 = D / c + c
// D / c + c must be an even integer, since x_1 is an integer.

const int MAXD = 2e5 + 5;

void solve()
{
    int D;
    cin >> D;

    // iterate over all possible x_2 - x_1.
    for (int c = 1; c <= MAXD; ++c) {
        if (D % c == 0) {
            int cand = (D / c + c);
            if (cand % 2 == 0) {
                int n_2 = cand / 2;
                int n_1 = n_2 - c;
                cout << n_1 << ' ' << n_2 << '\n';
                return;
            }
        }
    }
    cout << "impossible" << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
