class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                grid[i][j] = matrix[i][j] - '0';
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                if (grid[i][j + 1] > 0 && grid[i][j] > 0)
                {
                    grid[i][j] += grid[i][j + 1];
                }
            }
        }
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << grid[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        int maxx = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int limiting = grid[i][j];
                for (int k = i; k < m && grid[k][j] > 0; ++k)
                {
                    limiting = min(limiting, grid[k][j]);
                    maxx = max(maxx, (k - i + 1) * limiting);
                }
            }
        }
        return maxx;
    }
};
