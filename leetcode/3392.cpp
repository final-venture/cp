class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 2;
        int ret = 0;
        while (r < n)
        {
            int diff = nums[r] + nums[l];
            int cand = nums[(r + l) / 2];
            if ((cand % 2  == 0) && (diff == cand / 2))
            {
                ++ret;
            }
            ++r; ++l;
        }
        return ret;
    }
};
