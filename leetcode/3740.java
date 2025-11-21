class Solution {
    public int minimumDistance(int[] nums) {
        ArrayList<Integer> idxs = new ArrayList<>();
        int n = nums.length;
        int ret = Integer.MAX_VALUE;
        for (int i = 1; i <= 100; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] == i) {
                    idxs.add(j);
                }
            }
            int nn = idxs.size();
            for (int j = 2; j < nn; ++j) {
                int cand = 2*(idxs.get(j) - idxs.get(j - 2));
                ret = Math.min(ret, cand);
            }
            idxs.clear();
        }
        return (ret == Integer.MAX_VALUE) ? -1 : ret;
    }
}
