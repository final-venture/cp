#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

int n, MOD;
vector<int> ret;

int mod_sqr(int x)
{
    int mod_x = x % MOD;
    return (mod_x * mod_x) % MOD;
}

void solve()
{
    cin >> n >> MOD;
    ret.resize(n + 5);
    ret[0] = 1;
    ret[1] = 2;
    for (int i = 2; i < n + 5; ++i)
    {
        ret[i] = 1 + mod_sqr(ret[i - 1]) + mod_sqr(ret[i - 2]) * ((ret[i - 1] - mod_sqr(ret[i - 2]) + MOD) % MOD);
        ret[i] %= MOD;
    }
    cout << ret[n] % MOD;
}

signed main()
{
#ifndef LOCAL
    freopen("drivein.txt", "r", stdin);
    freopen("driveout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
