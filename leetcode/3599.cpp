class Solution
{
private:
    int k, n;
    vector<int> nums;
    vector<vector<int>> memo;

public:
    int dp(int idx, int remk)
    {
        if (!remk && idx >= n)
            return 0;
        if (!remk || idx >= n)
            return INT_MAX;
        if (memo[idx][remk] != -1)
        {
            return memo[idx][remk];
        }
        int curr = 0;
        int ret = INT_MAX;
        for (int i = idx + 1; i <= n; ++i)
        {
            curr ^= nums[i - 1];
            ret = min(ret, max(curr, dp(i, remk - 1)));
        }
        return memo[idx][remk] = ret;
    }
    int minXor(vector<int> &nums, int k)
    {
        this->k = k;
        this->nums = nums;
        n = nums.size();
        memo.resize(n + 5, vector<int>(k + 5, -1));
        return dp(0, k);
    }
};
