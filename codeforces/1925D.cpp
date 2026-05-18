#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
vector<int> fact;

void build_fact(int n) {
    fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
}

int bin_exp(int base, int exp) {
    int ret = 1;
    while (exp > 0) {
        if (exp & 1) {
            ret *= base;
            ret %= MOD;
        }
        base *= base;
        base %= MOD;
        exp /= 2;
    }
    return ret % MOD;
}

int divmod(int numer, int denom) {
    int inv = bin_exp(denom, MOD - 2);
    return (numer * inv) % MOD;
}

int C(int n, int r) {
    assert(n > 0 && r >= 0);
    assert(n >= r);
    int numer = fact[n];
    int denom = (fact[r] * fact[n - r]) % MOD;
    return divmod(numer, denom);
}

vector<int> f;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    f.resize(m);

    for (int i = 0; i < m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        cin >> f[i];
    }

    int N = C(n, 2); // total number of arrangements

    int S_1 = 0;
    for (int x = 1; x <= k; ++x) {
        int terms_1_2 = (x * C(k, x)) % MOD;
        int term_3 = bin_exp(N - 1, k - x);
        int total = (terms_1_2 * term_3) % MOD;
        S_1 += total;
        S_1 %= MOD;
    }
    int S_2 = 0;
    for (int x = 1; x <= k; ++x) {
        int terms_1_2 = (x * (x - 1)) % MOD;
        int terms_3_4 = (C(k, x) * bin_exp(N - 1, k - x)) % MOD;
        int total = (terms_1_2 * terms_3_4) % MOD;
        S_2 += total;
        S_2 %= MOD;
    }

    int EV_denom = bin_exp(N, k);

    int EV_numer_term_2 = (m * divmod(S_2, 2)) % MOD;
    int EV_numer_term_1 = accumulate(f.begin(), f.end(), 0LL) % MOD;
    EV_numer_term_1 = (EV_numer_term_1 * S_1) % MOD;

    int EV_numer = (EV_numer_term_1 + EV_numer_term_2) % MOD;

    int EV = divmod(EV_numer, EV_denom);
    cout << EV << '\n';

    // cout << bin_exp(5, 3) << '\n';
    // cout << bin_exp(5, 4) << '\n';
    // cout << C(5, 3) << '\n';
    // cout << divmod(10, 5) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    build_fact(MAXN);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
