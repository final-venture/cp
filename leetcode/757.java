class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (i1, i2) -> {
            if (i1[1] == i2[1]) {
                return Integer.compare(i2[0], i1[0]);
            }
            else {
                return Integer.compare(i1[1], i2[1]);
            }
        });

        int p1 = -1, p2 = -1;
        int n = intervals.length;
        int ret = 0;

        for (int i = 0; i < n; ++i) {
            int st = intervals[i][0], ed = intervals[i][1];
            if (p2 < st) {
                ret += 2;
                p1 = ed - 1;
                p2 = ed;
            }
            else if (p1 < st) {
                ++ret;
                p1 = p2;
                p2 = ed;
            }
        }

        return ret;
    }
}
