class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int ret = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            curr = max(curr + nums[i], nums[i]);
            ret = max(ret, curr);
        }
        return ret;
    }
};
