class Solution {
    private int getWaviness(int num) {
        int ret = 0;
        String numStr = String.valueOf(num);
        int n = numStr.length();
        for (int i = 1; i < n - 1; ++i) {
            int prev = numStr.charAt(i - 1) - '0';
            int curr = numStr.charAt(i) - '0';
            int next = numStr.charAt(i + 1) - '0';
            // peak
            if (prev < curr && curr > next) {
                ++ret;
            }
            else if (prev > curr && curr < next) {
                ++ret;
            }
        }
        return ret;
    }

    public int totalWaviness(int num1, int num2) {
        int ret = 0;
        for (int i = num1; i <= num2; ++i) {
            ret += getWaviness(i);
        }
        return ret;
    }
}
