class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        int currSum = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            currSum += nums[j];
            while (i <= j && currSum >= target)
            {
                currSum -= nums[i];
                ++i;
                res = min(res, j - i + 2);
            }
            ++j;
        }
        return (res == INT_MAX) ? 0 : res;
    }
};
