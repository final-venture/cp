class Solution
{
private:
    int n;
    vector<int> nums;
    int dp[100005][3][3];
    int dfs(int idx, int cnt, int rem)
    {
        if (cnt >= 3)
        {
            if (rem == 0)
            {
                return 0;
            }
            else
            {
                return -1e9;
            }
        }
        if (idx >= n)
        {
            return -1e9;
        }
        if (dp[idx][cnt][rem] != -1)
        {
            // cout << idx << ' ' << cnt << ' ' << rem << '\n';
            return dp[idx][cnt][rem];
        }
        int take = nums[idx] + dfs(idx + 1, cnt + 1, (rem + nums[idx]) % 3);
        int notTake = dfs(idx + 1, cnt, rem);
        return dp[idx][cnt][rem] = max(take, notTake);
    }

public:
    int maximumSum(vector<int> &nums)
    {
        n = nums.size();
        this->nums = nums;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        return max(0, dfs(0, 0, 0));
    }
};
