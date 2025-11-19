class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length;
        for (int i = 0; i < n;) {
            if (i == n - 1) {
                return true;
            }
            if (bits[i] == 1) {
                i += 2;
            } else if (bits[i] == 0) {
                ++i;
            }
        }
        return false;
    }
}