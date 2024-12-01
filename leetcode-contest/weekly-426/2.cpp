class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res = -1005;
        unordered_map<int, int> numSet;
        for (int i = 0; i < n; ++i)
            {
                ++numSet[nums[i]];
            }
        for (int i = 0; i < n; ++i)
            {
                --numSet[nums[i]];
                int nsum = sum - nums[i];
                if (!(nsum % 2) && numSet[nsum / 2])
                {
                    res = max(res, nums[i]);
                }
                ++numSet[nums[i]];
            }
        return res;
        }
    };
    