class Solution
{
public:
    vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int ret = 0;
    int rows, cols;
    vector<vector<int>> grid;
    vector<vector<int>> seen;
    bool valid(int r, int c)
    {
        return (0 <= r && r < rows && 0 <= c && c < cols);
    }
    int dfs(int r, int c)
    {
        if (grid[r][c] == 0 || seen[r][c])
        {
            return 0;
        }
        seen[r][c] = 1;
        int res = grid[r][c];
        for (auto &[dr, dc] : dirs)
        {
            int nr = r + dr, nc = c + dc;
            if (valid(nr, nc))
            {
                res += dfs(nr, nc);
            }
        }
        return res;
    }
    int findMaxFish(vector<vector<int>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        this->grid = grid;
        seen.resize(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (!seen[i][j])
                {
                    ret = max(ret, dfs(i, j));
                }
            }
        }
        return ret;
    }
};
