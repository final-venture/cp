class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        // start looping from nums[start]
        // loop from i = start to i = n - 1
        // loop from i = start to i = 0 (backwards)
        int n = nums.size();
        int minForward = INT_MAX;
        int minBackward = INT_MAX;
        for (int i = start; i < n; ++i) {
            if (nums[i] == target)
                minForward = min(minForward, i - start);
        }
        for (int i = start; i >= 0; --i) {
            if (nums[i] == target)
                minBackward = min(minBackward, start - i);
        }
        return min(minForward, minBackward);
    }
};
