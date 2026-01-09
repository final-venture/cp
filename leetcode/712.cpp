class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int sz1 = s1.size(), sz2 = s2.size();
        int accu = 0;
        for (int i = 0; i < sz1; ++i)
        {
            accu += s1[i];
        }
        for (int i = 0; i < sz2; ++i)
        {
            accu += s2[i];
        }
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));
        for (int i = 1; i <= sz1; ++i)
        {
            for (int j = 1; j <= sz2; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2 * s1[i - 1]);
                }
            }
        }
        return accu - dp[sz1][sz2];
    }
};
