class Solution {
    public int findFinalValue(int[] nums, int original) {
        HashSet<Integer> numSet = new HashSet<>();
        for (var num : nums) {
            numSet.add(num);
        }
        while (true) {
            if (numSet.contains(original)) {
                original *= 2;
            }
            else break;
        }
        return original;
    }
}
