#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MOD = 998244353;

int mod_exp(int base, int exp) {
    int ret = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            ret *= base;
            ret %= MOD;
        }
        base *= base;
        base %= MOD;
        exp /= 2;
    }
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<long double> a_quo;
    vector<long double> b_quo;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long double quo = (1.0 * a[i]) / a[j];
            a_quo.push_back(quo);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            long double quo = (1.0 * b[i]) / b[j];
            b_quo.push_back(quo);
        }
    }

    sort(a_quo.begin(), a_quo.end());
    sort(b_quo.begin(), b_quo.end());

    int a_idx = 0;
    int b_idx = 0;
    int a_sz = a_quo.size();
    int b_sz = b_quo.size();
    int inversion_cnt = 0;
    for (int i = 0; i < b_sz; ++i) {
        auto it = upper_bound(a_quo.begin(), a_quo.end(), b_quo[i]);
        inversion_cnt += distance(it, a_quo.end());
        inversion_cnt %= MOD;
    }

    int x = n * (n-1);
    cout << (inversion_cnt * mod_exp(x, MOD - 2)) % MOD << '\n';
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
