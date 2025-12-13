class Solution
{
private:
    int FULL_MASK, n;
    vector<vector<int>> dp;
    vector<int> nums1, nums2;
    int dfs(int idx, int curr_mask)
    {
        if (idx >= n || curr_mask == FULL_MASK)
        {
            return 0;
        }
        if (dp[idx][curr_mask] != -1)
        {
            return dp[idx][curr_mask];
        }
        int ret = INT_MAX;
        for (int bit = 0; bit < n; ++bit)
        {
            int curr_bit = (1 << bit);
            if (curr_mask >> bit & 1)
            {
                continue;
            }
            int cand = (nums1[idx] ^ nums2[bit]) + dfs(idx + 1, curr_mask | curr_bit);
            ret = min(ret, cand);
        }
        return dp[idx][curr_mask] = ret;
    }

public:
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
    {
        n = nums2.size();
        this->nums2 = nums2;
        this->nums1 = nums1;
        FULL_MASK = (1 << n) - 1;
        dp.resize(n, vector<int>(FULL_MASK + 1, -1));
        return dfs(0, 0);
    }
};
