class Solution
{
private:
    vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    vector<vector<int>> memo;
    vector<vector<int>> cells;
    vector<vector<int>> banned;
    int rows, cols;
    bool dfs(int r, int c)
    {
        if (banned[r][c])
        {
            return false;
        }
        if (r >= rows - 1)
        {
            return true;
        }
        if (memo[r][c] != -1)
        {
            return memo[r][c];
        }
        memo[r][c] = 0;
        bool ret = false;
        for (auto &[dr, dc] : dirs)
        {
            int nr = r + dr, nc = c + dc;
            if (0 <= nr && nr < rows && 0 <= nc && nc < cols)
            {
                ret |= dfs(nr, nc);
                if (ret)
                    break;
            }
        }
        return memo[r][c] = ret;
    }

    bool check(int t)
    {
        banned.assign(rows, vector<int>(cols, 0));
        for (int i = 0; i < t; ++i)
        {
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            banned[r][c] = 1;
        }
        memo.assign(rows, vector<int>(cols, -1));
        bool ret = false;
        for (int c = 0; c < cols; ++c)
        {
            ret |= dfs(0, c);
            if (ret)
                break;
        }
        return ret;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        rows = row;
        cols = col;
        this->cells = cells;
        int l = 0, r = rows * cols - 1;

        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (check(m))
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        return l - 1;
    }
};
