#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;

    ll power(ll base, ll exp) {
        ll res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    ll modInverse(ll n) {
        return power(n, MOD - 2);
    }

    ll combinations(int n, int k) {
        if (k < 0 || k > n) {
            return 0;
        }
        if (k == 0 || k == n) {
            return 1;
        }
        if (k > n / 2) {
            k = n - k;
        }
        ll res = 1;
        for (int i = 1; i <= k; ++i) {
            res = (res * (n - i + 1)) % MOD;
            res = (res * modInverse(i)) % MOD;
        }
        return res;
    }

    int countGoodArrays(int n, int m, int k) {
        ll combinations_nk = combinations(n - 1, k);
        ll first_element_choices = m;
        ll remaining_choices = power(m - 1, n - 1 - k);

        ll ret = (combinations_nk * first_element_choices) % MOD;
        ret = (ret * remaining_choices) % MOD;

        return (int)ret;
    }
};
