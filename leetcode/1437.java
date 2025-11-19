class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        if (k == 0)
            return true;
        int n = nums.length;
        int gap = (int) 2e5;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                if (gap < k) {
                    return false;
                }
                gap = 0;
            } else {
                ++gap;
            }
        }
        return true;
    }
}