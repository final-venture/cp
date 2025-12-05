class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int currSum = 0, ret = 0;
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            currSum += nums[i];
            if (abs(2*currSum - totalSum) % 2 == 0) {
                ++ret;
            }
        }        
        return ret;
    }
};
