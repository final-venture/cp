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
    return divv(nf, (sf % MOD * df % MOD) % MOD) % MOD;
}
