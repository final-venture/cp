class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int, greater<>> numSet(nums.begin(), nums.end());
        int ret = 0;
        int ok = 0;
        for (auto num : numSet) {
            if (!ok || num > 0) {
                ret += num;
                ok = 1;
            }
        }
        return ret;
    }
};
