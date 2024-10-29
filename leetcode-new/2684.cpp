class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxx = 0;
        vector<pair<int, int>> dirs = {{1, -1}, {0, -1}, {-1, -1}};
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        for (int r = 0; r < rows; r++)
        {
            dp[r][0] = 0;
        }

        for (int c = 1; c < cols; c++)
        {
            for (int r = 0; r < rows; r++)
            {
                int lmax = -1;
                for (const auto &[dr, dc] : dirs)
                {
                    if (0 <= r + dr && r + dr < rows && c + dc >= 0 && grid[r][c] > grid[r + dr][c + dc] && dp[r + dr][c + dc] > -1)
                    {
                        lmax = max(lmax, dp[r + dr][c + dc] + 1);
                    }
                }
                dp[r][c] = lmax;
                maxx = max(maxx, lmax);
            }
        }
        return maxx;
    }
};
