class Solution
{
private:
    int n, fullMask;
    vector<vector<int>> lists;
    vector<int> median;
    vector<int> length;
    vector<long long> dp;
    long long dfs(int mask)
    {
        if (__builtin_popcount(mask) <= 1)
        {
            return 0;
        }
        if (dp[mask] != -1)
        {
            return dp[mask];
        }
        long long ret = LLONG_MAX;

        // AI Help
        // ==========================================================================================================

        int lsb = mask & -mask;
        int otherBits = mask ^ lsb;

        for (int s = (otherBits - 1) & otherBits;; s = (s - 1) & otherBits)
        {
            int subset1 = s | lsb;
            int subset2 = mask ^ subset1;

            long long currentMergeCost = (long long)length[mask] + abs(median[subset1] - median[subset2]);
            long long total = dfs(subset1) + dfs(subset2) + currentMergeCost;

            if (total < ret)
            {
                ret = total;
            }

            if (s == 0)
                break;
        }

        // ==========================================================================================================

        return dp[mask] = ret;
    }

    void mergeIntoV1(vector<int> &v1, const vector<int> &v2)
    {
        int s1 = v1.size();
        int s2 = v2.size();

        v1.resize(s1 + s2);

        int i = s1 - 1;
        int j = s2 - 1;
        int k = s1 + s2 - 1;

        while (i >= 0 && j >= 0)
        {
            if (v1[i] > v2[j])
            {
                v1[k--] = v1[i--];
            }
            else
            {
                v1[k--] = v2[j--];
            }
        }

        while (j >= 0)
        {
            v1[k--] = v2[j--];
        }
    }

public:
    long long minMergeCost(vector<vector<int>> &lists)
    {
        this->lists = lists;
        n = lists.size();
        fullMask = (1 << n) - 1;
        median.resize(fullMask + 1);
        length.resize(fullMask + 1);
        dp.resize(fullMask + 1, -1);
        for (int i = 1; i <= fullMask; ++i)
        {
            vector<int> merged;
            for (int bit = 0; bit < n; ++bit)
            {
                if (i >> bit & 1)
                {
                    mergeIntoV1(merged, lists[bit]);
                }
            }
            length[i] = merged.size();
            median[i] = merged[(length[i] - 1) / 2];
        }
        return dfs(fullMask);
    }
};
