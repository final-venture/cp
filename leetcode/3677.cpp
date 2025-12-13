class Solution
{
private:
    int ilog2(unsigned long long n)
    {
        int log = 0;
        while (n >>= 1)
            ++log;
        return log;
    }

    int countSameBits(long long n)
    {
        if (n == 0)
            return 0;

        string s = "";
        long long temp = n;
        while (temp > 0)
        {
            s += ((temp & 1) ? '1' : '0');
            temp >>= 1;
        }
        reverse(s.begin(), s.end());

        int L = s.length();
        int k = (L + 1) / 2;

        long long prefixN = 0;
        for (int i = 0; i < k; i++)
        {
            prefixN = (prefixN << 1) | (s[i] - '0');
        }

        long long minPrefix = (1LL << (k - 1));

        long long count = prefixN - minPrefix;

        string pStr = "";
        long long pVal = prefixN;
        for (int i = k - 1; i >= 0; i--)
        {
            pStr += ((pVal >> i) & 1) ? '1' : '0';
        }

        string suffix = pStr;
        if (L % 2 == 1)
            suffix.pop_back();
        reverse(suffix.begin(), suffix.end());

        string fullPalindromeStr = pStr + suffix;

        if (fullPalindromeStr <= s)
        {
            count++;
        }

        return count;
    }

public:
    int countBinaryPalindromes(long long n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return 2;
        }
        int maxBit = ilog2(n);
        int ret = 2;
        for (int bit = 1; bit < maxBit; ++bit)
        {
            ret += (1 << (bit / 2));
        }

        return ret + countSameBits(n);
    }
};
