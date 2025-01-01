class Solution {
private:
    vector<int> nums;
    int dp[101][101][101];
    int k, op1, op2;
    int n;
public:
    int solve(int i, int rem1, int rem2)
    {
        if (i >= n) return 0;
        if (dp[i][rem1][rem2] != -1) return dp[i][rem1][rem2];
        // 1 | 2 | 1 -> 2 | 2 -> 1 | skip
        int ret = nums[i] + solve(i + 1, rem1, rem2);
        if (rem1)
        {
            int p1 = (nums[i] + 1) / 2;
            ret = min(ret, p1 + solve(i + 1, rem1 - 1, rem2));
            if (rem2 && p1 >= k)
            {
                ret = min(ret, p1 - k + solve(i + 1, rem1 - 1, rem2 - 1));
            }
        }
        if (rem2 && nums[i] >= k)
        {
            int p2 = nums[i] - k;
            ret = min(ret, p2 + solve(i + 1, rem1, rem2 - 1));
            if (rem1)
            {
                ret = min(ret, (p2 + 1) / 2 + solve(i + 1, rem1 - 1, rem2 - 1));
            }
        }
        return dp[i][rem1][rem2] = ret;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        this -> nums = nums;
        this -> k = k;
        this -> op1 = op1;
        this -> op2 = op2;
        this -> n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, op1, op2);
    }
};
