class Solution {
public:
    inline int longestPalindromeSubseq(string s1) {
        const int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int dp[n + 1][n + 1]; memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    continue;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }
};
