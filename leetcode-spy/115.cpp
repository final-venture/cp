// Memoisation
class Solution
{
private:
    string s;
    string t;
    vector<vector<int>> dp;

public:
    int numDistinct(string s, string t)
    {
        this->s = s;
        this->t = t;
        this->dp = vector<vector<int>>(s.size() + 1, vector<int>(t.size() + 1, -1));
        return dfs(0, 0);
    }

    int dfs(int i, int j)
    {
        if (j >= t.size())
            return 1;
        if (i >= s.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int take = 0;
        if (s[i] == t[j])
            take = dfs(i + 1, j + 1);
        int nottake = dfs(i + 1, j);
        return dp[i][j] = take + nottake;
    }
};

// DP
class Solution
{
private:
    string s;
    string t;
    vector<vector<double>> dp;

public:
    int numDistinct(string s, string t)
    {
        this->s = s;
        this->t = t;
        this->dp = vector<vector<double>>(s.size() + 1, vector<double>(t.size() + 1, 0));
        for (int i = 0; i < s.size() + 1; ++i)
        {
            dp[i][t.size()] = 1;
        }

        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = 0; j < t.size(); ++j)
            {
                double take = 0;
                if (s[i] == t[j])
                    take = dp[i + 1][j + 1];
                double nottake = dp[i + 1][j];
                dp[i][j] = take + nottake;
            }
        }

        return static_cast<int>(dp[0][0]);
    }
};
