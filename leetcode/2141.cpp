class Solution
{
private:
    bool check(long long t, long long n, long long sz, vector<int> &batteries)
    {
        long long summ = 0;
        for (int i = 0; i < sz; ++i)
        {
            summ += min(static_cast<long long>(batteries[i]), t); // contribution of each battery
        }
        return (summ >= t * n);
    }

public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        // what is the maximum times you can remove 1 from n elements in the array?
        int sz = batteries.size();
        long long l = 1;
        long long r = accumulate(batteries.begin(), batteries.end(), 0LL) / n + 20;

        while (l < r)
        {
            long long m = l + (r - l) / 2;
            if (check(m, n, sz, batteries))
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l - 1;
    }
};
