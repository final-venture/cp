class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 2;
        int ret = 0;
        while (r < n)
        {
            if (nums[r] - nums[l] == nums[r - l + 1] / 2 && !(nums[r - l + 1] & 1))
            {
                ++ret;
            }
            ++r; ++l;
        }
    }
};