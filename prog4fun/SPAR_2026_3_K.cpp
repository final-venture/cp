#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n, x;
        cin >> n >> x;

        __int128 curr = x;
        for (int i = 0; i < 62; ++i) {
            if (curr == 1) {
                cout << i << '\n';
                break;
            }
            curr *= curr;
            if (curr > n) {
                curr %= n;
                if (curr == 0) {
                    curr = n;
                }
            }
        }
        if (curr != 1) {
            cout << "impossible" << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
