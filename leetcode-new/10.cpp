class Solution
{
private:
    string s;
    string p;
    int dp[22][22];

public:
    bool isMatch(string s, string p)
    {
        this->s = s;
        this->p = p;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0);
    }
    bool dfs(int i, int j)
    {
        if (i >= s.size() && j >= p.size())
            return true;
        if (j >= p.size())
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];
        bool repeat = false, norepeat = false, match = false;
        if (j + 1 < p.size() && p[j + 1] == '*')
        {
            if (i < s.size() && (p[j] == s[i] || p[j] == '.'))
            {
                repeat = dfs(i + 1, j);
                match = dfs(i + 1, j + 2);
            }
            norepeat = dfs(i, j + 2);
        }
        else if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
            match = dfs(i + 1, j + 1);
        return dp[i][j] = repeat || norepeat || match;
    }
};
