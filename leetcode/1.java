class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        HashMap<Integer, Integer> numMap = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (numMap.containsKey(target - num)) {
                return new int[] { numMap.get(target - num), i };
            }
            numMap.put(num, i);
        }
        return new int[0];
    }
}
