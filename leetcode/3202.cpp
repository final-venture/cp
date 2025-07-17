class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ret = 0;
        vector<vector<int>> dp(k, vector<int>(k, 0));
        for (int i = 0; i < n; ++i)
        {
            int current_remainder = nums[i] % k;
            for (int previous_remainder = 0; previous_remainder < k; ++previous_remainder)
            {
                dp[current_remainder][previous_remainder] =
                    max(dp[current_remainder][previous_remainder],
                        dp[previous_remainder][current_remainder] + 1);
                ret = max(ret, dp[current_remainder][previous_remainder]);
            }
        }
        return ret;
    }
};
