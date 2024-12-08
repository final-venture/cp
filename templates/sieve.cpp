vector<int> spf;
void sieve(int n)
{
    spf.resize(n + 1, -1);
    for (long long i = 2; i < n + 1; ++i)
    {
        if (spf[i] != -1)
            continue;
        spf[i] = i;
        for (long long j = i * i; j < n + 1; j += i)
        {
            if (spf[j] != -1)
                continue;
            spf[j] = i;
        }
    }
}
