class Solution {
    public int minimumDistance(int[] nums) {
        int MAX = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            MAX = Math.max(MAX, nums[i] + 1);
        }

        ArrayList<ArrayList<Integer>> idxs = new ArrayList<>(MAX);
        for (int i = 0; i < MAX; ++i) {
            idxs.add(new ArrayList<>());
        }

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            idxs.get(num).add(i);
        }
        
        int ret = Integer.MAX_VALUE;
        for (int i = 0; i < MAX; ++i) {
            int nn = idxs.get(i).size();
            for (int j = 2; j < nn; ++j) {
                ret = Math.min(ret, 2*(idxs.get(i).get(j) - idxs.get(i).get(j - 2)));
            }
        }

        return ret == Integer.MAX_VALUE ? -1 : ret;
    }
}
