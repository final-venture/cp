#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
// #define LOCAL

void solve()
{
    int n, k;
    cin >> n >> k;
    int c1 = 0, c2, c3, c4;

    for (int i = 2; i <= n; ++i) {
        c1 = (c1 + k) % i;
        if (i == 2) {
            c2 = !c1;
        }
        else if (i > 2) {
            c2 = (c2 + k) % i;
        }
        if (i == 3) {
            for (int j = 0; j < 3; ++j) {
                if (c1 != j && c2 != j) {
                    c3 = j;
                }
            }
        }
        else if (i > 3) {
            c3 = (c3 + k) % i;
        }
        if (i == 4) {
            for (int j = 0; j < 4; ++j) {
                if (c1 != j && c2 != j && c3 != j) {
                    c4 = j;
                }
            }
        }
        else if (i > 4) {
            c4 = (c4 + k) % i;
        }
    }

    vector<int> ret {c4, c3, c2, c1};

    // reverse(ret.begin(), ret.end());
    for (int x : ret) {
        cout << x + 1 << ' ';
    }
}

signed main()
{
#ifndef LOCAL
    freopen("teamin.txt", "r", stdin);
    freopen("teamout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
