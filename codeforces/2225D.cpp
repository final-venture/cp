#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MOD = 998244353;

int get_count_mod4(int d, int m) {
    if (d - m < 0) {
        return 0;
    }
    return (d - m) / 4 + 1;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    int onemod4 = ( get_count_mod4(x - 1, 1) % MOD) * ( (get_count_mod4(n, 1) - get_count_mod4(x - 1, 1)) % MOD );
    int threemod4 = ( (get_count_mod4(x - 1, 3) + 1) % MOD )* ( (get_count_mod4(n, 3) - get_count_mod4(x - 1, 3)) % MOD);
    cout << (onemod4 + threemod4) % MOD << '\n';
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
