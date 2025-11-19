class Solution {
    public int maximizeExpressionOfThree(int[] nums) {
        int maxx1 = Integer.MIN_VALUE;
        int maxx2 = maxx1;
        int minn = Integer.MAX_VALUE;
        int n = nums.length;

        for (int num : nums) {
            if (num > maxx1) {
                maxx2 = maxx1;
                maxx1 = num;
            } else if (num > maxx2) {
                maxx2 = num;
            }

            if (num < minn) {
                minn = num;
            }
        }

        return maxx1 + maxx2 - minn;
    }
}