class Solution {
    public int countPalindromicSubsequence(String s) {
        // u can only have palindromes of form xyx, where x and y COULD be the same letter
        // seen[a][b] means aba has been seen.
        boolean[][] seen = new boolean[26][26];
        int n = s.length();

        for (char x = 'a'; x <= 'z'; ++x) {
            int l = 0, r = n - 1;
            while (l < n) {
                if (s.charAt(l) == x) {
                    break;
                }
                ++l;
            }
            while (r >= 0) {
                if (s.charAt(r) == x) {
                    break;
                }
                --r;
            }

            if (l >= r) {
                continue;
            }

            
            for (int i = l + 1; i < r; ++i) {
                // System.out.println(i);
                char y = s.charAt(i);
                seen[x - 'a'][y - 'a'] = true;
            }
        }

        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (seen[i][j]) {
                    ++ret;
                }
            }
        }

        return ret;
    }
}
