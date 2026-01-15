class Solution
{
public:
    long long minimumCost(string s, string t, int fc, int sc, int cc)
    {
        long long s0t1 = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0' && t[i] == '1')
            {
                s0t1++;
            }
            else if (s[i] == '1' && t[i] == '0')
            {
                s1t0++;
            }
        }
        long long ret = 0;
        if (s1t0 && s0t1)
        {
            long long toRemove = min(s1t0, s0t1);
            ret += min(toRemove * fc * 2LL, toRemove * sc * 1LL);
            s1t0 -= toRemove;
            s0t1 -= toRemove;
        }
        if (s1t0)
        {
            long long pairs = s1t0 / 2;
            ret += min(pairs * (cc + (long long)sc) * 1LL, fc * pairs * 2LL);
            s1t0 -= pairs * 2;
        }
        else if (s0t1)
        {
            long long pairs = s0t1 / 2;
            ret += min(pairs * (cc + (long long)sc) * 1LL, fc * pairs * 2LL);
            s0t1 -= pairs * 2;
        }
        if (s1t0)
        {
            ret += fc;
        }
        else if (s0t1)
        {
            ret += fc;
        }

        return ret;
    }
};
