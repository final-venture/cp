class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < cols; ++i)
        {
            for (int j = 1; j < rows; ++j)
            {
                if (grid[j][i] <= grid[j - 1][i])
                {
                    cnt += (grid[j - 1][i] - grid[j][i] + 1);
                    grid[j][i] = grid[j - 1][i] + 1;
                }
            }
        }
        return cnt;
    }
}; ©leetcode