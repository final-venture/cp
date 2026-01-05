class Solution
{
private:
    int d;
    int n, m;
    long long pfx[755][755][2];
    const int MOD = 1e9 + 7;
    long long dfs(int r, int c, int same, vector<string> &grid)
    {
        if (r >= n)
        {
            return 1;
        }
        long long ret = 0;
        if (grid[r][c] == '#')
        {
            pfx[r][c + 1][same] = pfx[r][c][same] + ret;
            pfx[r][754][same] = c + 1;
            return ret;
        }
        if (!same)
        {
            int lb = max(0, c - d);
            int ub = min(m - 1, c + d) + 1;
            if (pfx[r][754][1] < ub)
            {
                for (int i = pfx[r][754][1] + 1; i <= ub; ++i)
                {
                    dfs(r, i - 1, 1, grid);
                }
            }
            ret += pfx[r][ub][1] - pfx[r][lb][1];
            ret -= pfx[r][c + 1][1] - pfx[r][c][1];
            ret %= MOD;
        }
        if (r >= n - 1)
        {
            ret += dfs(r + 1, 0, 0, grid);
            ret %= MOD;
        }
        else
        {
            int lb = max(0, c - d + 1);
            int ub = min(m - 1, c + d - 1) + 1;
            if (pfx[r + 1][754][0] < ub)
            {
                for (int i = pfx[r + 1][754][0] + 1; i <= ub; ++i)
                {
                    dfs(r + 1, i - 1, 0, grid);
                }
            }
            ret += pfx[r + 1][ub][0] - pfx[r + 1][lb][0];
            ret %= MOD;
        }
        pfx[r][c + 1][same] = pfx[r][c][same] + ret;
        pfx[r][754][same] = c + 1;
        return ret;
    }

public:
    int numberOfRoutes(vector<string> &grid, int d)
    {
        this->d = d;
        n = grid.size();
        m = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; ++i)
        {
            ret += dfs(0, i, 0, grid);
            ret %= MOD;
        }
        return ret;
    }
};
