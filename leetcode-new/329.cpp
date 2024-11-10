class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int res = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> indegree(rows, vector<int>(cols, 0));
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                for (auto &[dr, dc] : dirs)
                {
                    int nr = r + dr, nc = c + dc;
                    if (0 <= nr && nr < rows && 0 <= nc && nc < cols &&
                        matrix[nr][nc] < matrix[r][c])
                        ++indegree[r][c];
                }
            }
        }

        queue<tuple<int, int, int>> q;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (!indegree[r][c])
                    q.push({r, c, 1});
            }
        }
        while (!q.empty())
        {
            auto [r, c, l] = q.front();
            q.pop();
            res = max(res, l);
            for (auto &[dr, dc] : dirs)
            {
                int nr = r + dr, nc = c + dc;
                if (0 <= nr && nr < rows && 0 <= nc && nc < cols &&
                    matrix[nr][nc] > matrix[r][c])
                {
                    --indegree[nr][nc];
                    if (!indegree[nr][nc])
                        q.push({nr, nc, l + 1});
                }
            }
        }
        return res;
    }
};
