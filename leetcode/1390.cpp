class Solution
{
private:
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
        spf[1] = 1;
    }

public:
    int sumFourDivisors(vector<int> &nums)
    {
        int n = nums.size();
        int ret = 0;
        // 4 divisors means either x = a^3, or x = a^1 * b^1
        sieve(1e5 + 5);
        for (int i = 0; i < n; ++i)
        {
            int a = spf[nums[i]];
            if (a == nums[i])
            {
                continue;
            }
            int b = nums[i] / spf[nums[i]];
            if (a == b)
            {
                continue;
            }
            if (spf[b] == b)
            {
                ret += 1 + nums[i] + a + b;
            }
            else if (a * a * a == nums[i])
            {
                ret += 1 + nums[i] + a + a * a;
            }
        }
        return ret;
    }
};
