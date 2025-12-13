class Solution
{
public:
    int maximumXorProduct(long long a, long long b, int n)
    {
        const long long MOD = 1e9 + 7;
        for (int i = n - 1; i >= 0; --i)
        {
            // for (int i = 0; i < n; ++i) {
            bool aHasBit = (a >> i & 1);
            bool bHasBit = (b >> i & 1);
            if (!aHasBit && !bHasBit)
            {
                a |= (1LL << i);
                b |= (1LL << i);
                continue;
            }

            long long diff = abs(b - a);
            if ((aHasBit && !bHasBit) || (!aHasBit && bHasBit))
            {
                long long newA = a ^ (1LL << i), newB = b ^ (1LL << i);
                // cout << a << ' ' << b << '\n';
                long long newDiff = abs(newB - newA);
                if (newDiff < diff)
                {
                    a = newA;
                    b = newB;
                }
            }
        }
        // cout << a << ' ' << b << '\n';
        return (a % MOD) * (b % MOD) % MOD;
    }
};
