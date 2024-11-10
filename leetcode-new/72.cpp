// Memoisation
class Solution
{
private:
    int n1;
    int n2;
    int dp[501][501];

public:
    int minDistance(string word1, string word2)
    {
        this->n1 = word1.size();
        this->n2 = word2.size();

        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, word1, word2);
    }

    int dfs(int i, int j, string &word1, string &word2)
    {
        if (i >= n1)
            return n2 - j;
        if (j >= n2)
            return n1 - i;
        if (dp[i][j] != -1)
            return dp[i][j];

        int match = 1e4;
        if (word1[i] == word2[j])
            match = dfs(i + 1, j + 1, word1, word2);
        int replace = 1 + dfs(i + 1, j + 1, word1, word2);
        int remove = 1 + dfs(i + 1, j, word1, word2);
        int insert = 1 + dfs(i, j + 1, word1, word2);
        return dp[i][j] = min({match, replace, remove, insert});
    }
};
