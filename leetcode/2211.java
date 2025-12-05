class Solution {
    public int countCollisions(String directions) {
        int n = directions.length();
        int ret = 0;
        boolean[] isBarrier = new boolean[n];
        if (n == 1) return 0;
        for (int i = 1; i < n; ++i) {
            if (directions.charAt(i) == 'L' && directions.charAt(i - 1) == 'R') {
                isBarrier[i] = true;
                isBarrier[i - 1] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (directions.charAt(i) == 'S') {
                isBarrier[i] = true;
            }
        }
        
        boolean ok = false;
        // Leftward
        for (int i = 0; i < n; ++i) {
            if (directions.charAt(i) == 'L' && ok == true) {
                ++ret;
            }
            ok = ok | isBarrier[i];
        }
        
        ok = false;

        // Rightward
        for (int i = n - 1; i >= 0; --i) {
            if (directions.charAt(i) == 'R' && ok == true) {
                ++ret;
            }
            ok = ok | isBarrier[i];
        }

        return ret;
    }
}
