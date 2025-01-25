#define ll long long
#define MOD 1000000007
class Solution
{
public:
    vector<ll> fct;
    ll C(int n, int r)
    {
        if (r > n)
            return 0;
        if (r == n || r == 0)
            return 1;
        ll num = fct[n];
        ll den = fct[r] * fct[n - r] % MOD;
        return div_mod(num, den);
    }
    ll div_mod(int end, int sor)
    {
        return end * mod_exp(sor, MOD - 2) % MOD;
    }
    ll mod_exp(ll base, ll pwr)
    {
        ll ret = 1;
        while (pwr)
        {
            if (pwr & 1)
            {
                ret *= base;
                ret %= MOD;
            }
            base *= base;
            base %= MOD;
            pwr /= 2;
        }
        return ret;
    }
    int distanceSum(int m, int n, int k)
    {
        fct.resize(m * n + 1);
        fct[0] = 1;
        for (int i = 1; i <= m * n; ++i)
        {
            fct[i] = fct[i - 1] * i;
            fct[i] %= MOD;
        }
        ll ret = 0;
        ll mult = C(n * m - 2, k - 2);
        for (ll i = 1; i <= m - 1; ++i)
        {
            ret += n * n * i * (m - i);
            ret %= MOD;
        }
        for (ll i = 1; i <= n - 1; ++i)
        {
            ret += m * m * i * (n - i);
            ret %= MOD;
        }
        ret *= mult;
        ret %= MOD;
        return ret;
    }
};
