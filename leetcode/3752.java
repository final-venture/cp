class Solution {
    public int[] lexSmallestNegatedPerm(int n, long target) {
        long longN = n;
        long positiveSum = longN * (longN + 1) / 2;
        if (positiveSum < Math.abs(target)) {
            return new int[0];
        }
        if ((positiveSum & 1) != (Math.abs(target) & 1)) {
            return new int[0];
        }

        ArrayList<Integer> ret = new ArrayList<>();
        boolean[] banned = new boolean[n + 1];

        for (int i = n; i > 0; --i) {
            if (positiveSum - 2*i >= target) {
                ret.add(-i);
                positiveSum -= 2*i;
                banned[i] = true;
            }
        }
        // System.out.println(positiveSum);
        for (int i = 1; i <= n; ++i) {
            if (banned[i]) continue;
            ret.add(i);
        }

        int[] ret2 = new int[n];
        for (int i = 0; i < n; ++i) {
            ret2[i] = ret.get(i);
        }

        return ret2;
    }
}
