#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

const int MAXRET = 259;

void solve()
{
    int n;
    cin >> n;
    for (int it = 0; it < n; ++it) {
        int x;
        cin >> x;
        for (int i = 0; i < MAXRET; ++i) {
            if ((i ^ (i << 1)) % 256 == x) {
                cout << i << ' ';
                break;
            }
        }
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        solve();
    return 0;
}
