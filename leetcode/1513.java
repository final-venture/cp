class Solution {
    public int numSub(String s) {
        final int MOD = (int) (1e9 + 7);
        int l = 0, r = 0;
        int n = s.length();
        int ret = 0;
        while (r < n) {
            if (s.charAt(l) == '1') {
                ret += (r - l + 1);
                ret %= MOD;
            }
            ++r;
            if (r < n && s.charAt(r) != s.charAt(l)) {
                l = r;
            }
        }
        return ret;
    }
}