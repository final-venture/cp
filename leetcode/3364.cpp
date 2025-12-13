class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<int> pfx(nums.size() + 1);
        int minn = INT_MAX;
        for (int i = 1; i < nums.size() + 1; ++i)
        {
            pfx[i] = pfx[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + l - 1; j < nums.size() && j <= i + r - 1; ++j)
            {
                int res = pfx[j + 1] - pfx[i];
                if (res > 0)
                {
                    minn = min(minn, res);
                }
            }
        }
        return (minn == INT_MAX) ? -1 : minn;
    }
};
