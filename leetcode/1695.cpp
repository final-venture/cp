class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        unordered_set<int> curr_seen;
        int curr_sum = 0;
        int ret = 0;
        while (r < n) {
            curr_sum += nums[r];
            while (curr_seen.contains(nums[r])) {
                curr_seen.erase(nums[l]);
                curr_sum -= nums[l];
                ++l;
            }
            curr_seen.insert(nums[r]);
            ++r;
            ret = max(ret, curr_sum);
        }
        return ret;
    }
};
