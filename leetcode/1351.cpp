class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int ret = 0;
        int m = grid.size(), n = grid[0].size();
        int r = n - 1;
        for (int i = 0; i < m; ++i)
        {
            for (; r >= 0 && grid[i][r] < 0; --r)
            {
                continue;
            }
            ret += n - r - 1;
        }
        return ret;
    }
};
