class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        for (int cr = 0; cr < r; cr++)
        {
            dp[cr][0] = matrix[cr][0];
            res += dp[cr][0];
        }
        for (int cc = 1; cc < c; cc++)
        {
            dp[0][cc] = matrix[0][cc];
            res += dp[0][cc];
        }
        for (int cr = 1; cr < r; cr++)
        {
            for (int cc = 1; cc < c; cc++)
            {
                if (matrix[cr][cc] == 1)
                {
                    dp[cr][cc] = 1 + min({dp[cr][cc - 1], dp[cr - 1][cc], dp[cr - 1][cc - 1]});
                }
                res += dp[cr][cc];
            }
        }
        return res;
    }
};
