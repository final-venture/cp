// FIRST ATTEMPT
class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        int ALL = 1 << n;
        int ret_cnt = -1, ret = -1;
        for (int mask = 0; mask < ALL; ++mask)
        {
            int cand = 0;
            for (int bit = 0; bit < n; ++bit)
            {
                if ((mask >> bit) & 1)
                {
                    cand |= nums[bit];
                }
            }
            if (cand > ret)
            {
                ret = cand;
                ret_cnt = 1;
            }
            else if (cand == ret)
            {
                ++ret_cnt;
            }
        }
        return ret_cnt;
    }
};

// ELEGANT:
class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        int ALL = 1 << n;
        vector<int> dp(ALL + 1, 0);
        dp[0] = 1;
        int maxx = 0;
        for (int x : nums)
        {
            for (int i = maxx; i >= 0; --i)
            {
                dp[x | i] += dp[i];
            }
            maxx |= x;
        }
        return dp[maxx];
    }
};
