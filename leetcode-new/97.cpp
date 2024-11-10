// Memoisation
class Solution
{
private:
    string s1;
    string s2;
    string s3;
    int dp[101][101];

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3.size() != s1.size() + s2.size())
            return false;
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0);
    }

    bool dfs(int idx1, int idx2)
    {
        int idx3 = idx1 + idx2;
        if (idx3 == s3.size())
            return true;
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        bool match1 = false;
        bool match2 = false;
        if (idx1 < s1.size() && s1[idx1] == s3[idx3])
            match1 = dfs(idx1 + 1, idx2);
        if (idx2 < s2.size() && s2[idx2] == s3[idx3])
            match2 = dfs(idx1, idx2 + 1);
        return dp[idx1][idx2] = (match1 || match2);
    }
};

// Tabulation
class Solution
{
private:
    string s1;
    string s2;
    string s3;
    bool dp[101][101];

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3.size() != s1.size() + s2.size())
            return false;
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        memset(dp, false, sizeof(dp));

        dp[s1.size()][s2.size()] = true;

        for (int i = s1.size() - 1; i >= 0; i--)
        {
            dp[i][s2.size()] = dp[i + 1][s2.size()] && s1[i] == s3[i + s2.size()];
        }

        for (int j = s2.size() - 1; j >= 0; j--)
        {
            dp[s1.size()][j] = dp[s1.size()][j + 1] && s2[j] == s3[j + s1.size()];
        }

        for (int i = s1.size() - 1; i >= 0; --i)
        {
            for (int j = s2.size() - 1; j >= 0; --j)
            {
                int k = i + j;
                dp[i][j] = (s1[i] == s3[k] && dp[i + 1][j]) ||
                           (s2[j] == s3[k] && dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};
