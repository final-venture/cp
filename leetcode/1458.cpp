class Solution
{
private:
    int n1, n2;
    vector<vector<int>> dp;
    vector<int> nums1, nums2;
    int dfs(int idx1, int idx2)
    {
        if (idx1 >= n1 || idx2 >= n2)
        {
            return 0;
        }
        if (dp[idx1][idx2] != -1)
        {
            return dp[idx1][idx2];
        }
        int ret = dfs(idx1 + 1, idx2);
        ret = max(ret, dfs(idx1, idx2 + 1));
        ret = max(ret, nums1[idx1] * nums2[idx2] + dfs(idx1 + 1, idx2 + 1));
        return dp[idx1][idx2] = ret;
    }

public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        n1 = nums1.size();
        n2 = nums2.size();
        dp.resize(n1, vector<int>(n2, -1));
        int ret = dfs(0, 0);
        if (ret <= 0)
        {
            ret = INT_MIN;
            for (int i = 0; i < n1; ++i)
            {
                for (int j = 0; j < n2; ++j)
                {
                    ret = max(ret, nums1[i] * nums2[j]);
                }
            }
        }
        return ret;
    }
};
