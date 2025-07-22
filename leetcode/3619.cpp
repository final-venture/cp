class Solution {
private:
    vector<vector<int>> grid;
    vector<pair<int, int>> dirs {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    vector<vector<int>> seen;
    int m, n;
    int dfs(int r, int c) {
        if (seen[r][c] || grid[r][c] == 0) {
            return 0;
        }
        long long ret = grid[r][c];
        seen[r][c] = 1;
        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (0 <= nr && nr < m && 0 <= nc && nc < n) {
                ret += dfs(nr, nc);   
            }
        }
        return ret;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        seen.resize(m, vector<int>(n, 0));
        this -> grid = grid;
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (seen[i][j] || grid[i][j] == 0) {
                    continue;
                }
                long long cand = dfs(i, j);
                if (cand % k == 0) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};
