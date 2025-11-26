class Solution
{
private:
    vector<vector<vector<int>>> dp;
    int m, n, k;
    vector<pair<int, int>> dirs{{1, 0}, {0, 1}};
    vector<vector<int>> grid;
    const int MOD = 1e9 + 7;

    inline bool valid(int r, int c)
    {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    int dfs(int r, int c, int sum)
    {
        if (!valid(r, c))
            return 0;
        if (r == m - 1 && c == n - 1 && sum == 0)
        {
            return 1;
        }
        if (dp[r][c][sum] != -1)
        {
            return dp[r][c][sum];
        }
        int ret = 0;
        for (auto &[dr, dc] : dirs)
        {
            int nr = r + dr, nc = c + dc;
            if (!valid(nr, nc))
                continue;
            int newSum = grid[nr][nc] + sum;
            if (newSum >= k)
            {
                newSum %= k;
            }
            ret += dfs(nr, nc, newSum);
        }
        return dp[r][c][sum] = ret % MOD;
    }

public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        this->grid = grid;
        this->k = k;
        m = grid.size();
        n = grid[0].size();
        dp.resize(m + 3, vector<vector<int>>(n + 3, vector<int>(k + 3, -1)));
        // for (int i = 0; i < m + 3; ++i) {
        //     for (int j = 0; j < n + 3; ++j) {
        //         for (int k = 0; k <= 101; ++k) {
        //             dp[i][j][k] = -1;
        //         }
        //     }
        // }
        return dfs(0, 0, grid[0][0] % k);
    }
};
