class Solution {
    public int minimumFlips(int n) {
        final int LOG = (int)(Math.log(n) / Math.log(2) + 1);
        // System.out.println(LOG);
        // if (n == 1) return 0;

        ArrayList<Integer> numArr = new ArrayList<>();
        int ret = 0;
        for (int i = 0; i < LOG; ++i) {
            if (((n >> i) & 1) == 1) {
                numArr.add(1);
            }
            else {
                numArr.add(0);
            }
        }

        // for (var x : numArr) {
        //     System.out.println(x);
        // }

        int sz = numArr.size();
        for (int i = 0; i < sz / 2; ++i) {
            int j = sz - i - 1;
            if (numArr.get(i) != numArr.get(j)) {
                ret += 2;
            }
        }
        return ret;
    }
}
