class Solution
{
private:
    int dp[20][2001];
    int target;

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        this->target = target;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, nums);
    }

    int dfs(int i, int csum, vector<int> &nums)
    {
        if (i >= nums.size())
        {
            if (csum == target)
                return 1;
            return 0;
        }
        if (dp[i][csum + 1000] != -1)
            return dp[i][csum + 1000];
        int pos = dfs(i + 1, csum + nums[i], nums);
        int neg = dfs(i + 1, csum - nums[i], nums);
        return dp[i][csum + 1000] = pos + neg;
    }
};
