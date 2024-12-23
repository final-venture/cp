class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prev = INT_MIN;
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            int cand = min(max(prev + 1, nums[i] - k), nums[i] + k);
            if (cand > prev) ++ret;
            prev = cand;
        }
        return ret;
    }
};
