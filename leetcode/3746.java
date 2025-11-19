class Solution {
    public int minLengthAfterRemovals(String s) {
        int n = s.length();
        HashMap<Character, Integer> cnts = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            cnts.put(c, cnts.getOrDefault(c, 0) + 1);
        }
        return Math.abs(cnts.getOrDefault('a', 0) - cnts.getOrDefault('b', 0));
    }
}
