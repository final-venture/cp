class Solution {
private:
    vector<int> primes;
public:
    void genPrimes(int n)
    {
        primes.resize(n + 1, 1);
        int s = sqrtl(n);
        for (int i = 2; i <= s; ++i)
        {
            if (!primes[i]) continue;
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        genPrimes(right);
        int r = max(2, left); int prev = -1;
        int minn = INT_MAX;
        pair<int, int> res = { -1, -1};
        while (r <= right)
        {
            if (primes[r])
            {
                if (prev != -1 && r - prev < minn)
                {
                    res = {prev, r};
                    minn = r - prev;
                }
                prev = r;
            }
            ++r;
        }
        return {res.first, res.second};
    }
};
