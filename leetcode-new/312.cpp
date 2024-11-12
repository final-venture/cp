class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int dp[302][302];
        memset(dp, 0, sizeof(dp));

        for (int i = n; i >= 1; --i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i > j)
                    continue;
                int maxx = INT_MIN;
                for (int idx = i; idx <= j; ++idx)
                {
                    int newscore = nums[i - 1] * nums[idx] * nums[j + 1] +
                                   dp[i][idx - 1] + dp[idx + 1][j];
                    maxx = max(maxx, newscore);
                }
                dp[i][j] = maxx;
            }
        }
        return dp[1][n];
    }
};
