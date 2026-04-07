#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    int nCopy = n;
    int ret = 1;
    for (int i = 2; i * i <= nCopy; ++i) {
        int f1 = i;
        while (nCopy % f1 == 0) {
            if (ret % f1 > 0) {
                ret *= f1;
            }
            nCopy /= f1;
        }
    }
    ret *= nCopy;
    cout << ret << '\n';
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
