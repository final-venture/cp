class Solution
{
public:
    long long numGoodSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> modPfx(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            modPfx[i] = modPfx[i - 1] + nums[i - 1];
            modPfx[i] %= k;
        }
        unordered_map<int, int> modCnt;
        modCnt[0] = 1;
        long long ret = 0;

        for (int i = 1; i <= n; ++i)
        {
            int currMod = modPfx[i];
            ret += modCnt[currMod];
            ++modCnt[currMod];
        }

        long long run = 0;
        int mod0Cnt = 0;
        long long toSubtract = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i <= 0 || nums[i] != nums[i - 1])
            {
                run = 0;
                mod0Cnt = 0;
            }
            toSubtract += mod0Cnt;
            run += nums[i];
            if (run % k == 0)
            {
                ++mod0Cnt;
            }
        }

        return ret - toSubtract;
    }
};
