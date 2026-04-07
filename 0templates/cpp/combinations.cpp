int mod_exp(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int divmod(int a, int b)
{
    return a * mod_exp(b, MOD - 2) % MOD;
}

int C(int n, int r)
{
    if (r == n)
        return 1;
    int nf = fct[n];
    int sf = fct[n - r];
    int df = fct[r];
    return divmod(nf, (sf % MOD * df % MOD) % MOD) % MOD;
}

void build_nCr() {
    nCr.resize(MAXN, vector<int>(MAXN));
    for (int r = 0; r < MAXN; ++r) {
        nCr[0][r] = 0;
    }
    for (int n = 0; n < MAXN; ++n) {
        nCr[n][0] = 1;
    }
    for (int n = 1; n < MAXN; ++n) {
        for (int r = 1; r < MAXN; ++r) {
            nCr[n][r] = (nCr[n - 1][r - 1] + nCr[n - 1][r]) % MOD;
        }
    }
}

void build_fact() {
    fact.resize(MAXN);
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
