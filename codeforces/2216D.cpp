#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    const int SQRT = sqrtl(n);
    int ret = 0;
    for (int i = 1; i * i <= n + 5; ++i) {
        if (n % i != 0) {
            continue;
        }
        int b1 = i - 1;
        int b2 = n / i - 1;
        if (b1 > SQRT && b1 > b2) {
            ++ret;
        }
        else if (b2 > SQRT && b2 > b1) {
            ++ret;
        }
    }

    for (int i = 2; i <= SQRT; ++i) {
        int L[50];
        int sz = 0;

        int nCopy = n;
        while (nCopy) {
            L[sz++] = (nCopy % i);
            nCopy /= i;
        }

        for (int j = 2; j <= sz; ++j) {
            if (sz % j != 0) {
                continue;
            }
            bool ok = true;
            for (int k = 0; k < sz; ++k) {
                if (L[k] != L[k - (k % j)]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ++ret;
            }
        }
    }
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
