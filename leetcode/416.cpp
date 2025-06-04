// Brute Force
class Solution
{
private:
    int target = 0;
    vector<int> nums;

public:
    bool canPartition(vector<int> &nums)
    {
        this->nums = nums;
        for (int num : nums)
        {
            target += num;
        }
        if (target % 2)
            return false;
        target /= 2;
        return dfs(0, 0);
    }

    bool dfs(int idx, int sum)
    {
        if (sum == target)
            return true;
        if (idx >= nums.size())
            return false;
        return dfs(idx + 1, sum + nums[idx]) || dfs(idx + 1, sum);
    }
};

// Memoisation
class Solution
{
private:
    int target = 0;
    int n;
    vector<vector<int>> dp;
    vector<int> nums;

public:
    bool canPartition(vector<int> &nums)
    {
        this->nums = nums;
        this->n = nums.size();

        for (int num : nums)
        {
            target += num;
        }
        if (target % 2)
            return false;
        target /= 2;
        this->dp = vector<vector<int>>(n, vector<int>(target + 1, -1));
        return dfs(0, 0);
    }

    bool dfs(int idx, int sum)
    {
        if (sum == target)
            return true;
        if (idx >= n)
            return false;
        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        bool take = false;
        bool ntake = dfs(idx + 1, sum);
        if (nums[idx] + sum <= target)
            take = dfs(idx + 1, sum + nums[idx]);
        return dp[idx][sum] = take || ntake;
    }
};
