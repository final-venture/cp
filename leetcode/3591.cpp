class Solution
{
private:
    bool isPrime(int x)
    {
        if (x == 1)
            return false;
        for (int i = 2; i < 40; ++i)
        {
            for (int j = 2; j < 40; ++j)
            {
                if (i * j == x)
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool checkPrimeFrequency(vector<int> &nums)
    {
        vector<int> freqs(105, 0);
        for (auto num : nums)
        {
            ++freqs[num];
        }
        for (int i = 0; i < 105; ++i)
        {
            if (!freqs[i])
                continue;
            if (isPrime(freqs[i]))
            {
                return true;
            }
        }
        return false;
    }
};
