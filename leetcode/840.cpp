class Solution
{
private:
    bool allEqual(vector<int> &vec)
    {
        int n = vec.size();
        for (int i = 1; i < n; ++i)
        {
            if (vec[i] != vec[i - 1])
            {
                return false;
            }
        }
        return true;
    }
    bool checkGrid(int sr, int sc, vector<vector<int>> &grid)
    {
        vector<int> rowSums(3, 0);
        vector<int> colSums(3, 0);
        unordered_set<int> numSet;
        for (int r = sr; r < sr + 3; ++r)
        {
            for (int c = sc; c < sc + 3; ++c)
            {
                rowSums[r - sr] += grid[r][c];
                colSums[c - sc] += grid[r][c];
                if (grid[r][c] > 9 || grid[r][c] <= 0)
                    return false;
                numSet.insert(grid[r][c]);
            }
        }

        if (grid[sr][sc] + grid[sr + 2][sc + 2] !=
            grid[sr + 2][sc] + grid[sr][sc + 2])
            return false;

        return (allEqual(rowSums) && allEqual(colSums) && numSet.size() == 9);
    }

public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int ret = 0;
        for (int sr = 0; sr <= rows - 3; ++sr)
        {
            for (int sc = 0; sc <= cols - 3; ++sc)
            {
                ret += checkGrid(sr, sc, grid);
            }
        }
        return ret;
    }
};
