class Solution
{
private:
    int timer = 0;
    vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int n;

public:
    bool valid(int r, int c)
    {
        return (0 <= r && r < n && 0 <= c && c < n);
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        vector<vector<int>> sz(n, vector<int>(n, 0));
        vector<vector<int>> ids(n, vector<int>(n, -1));
        vector<vector<int>> seen(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!seen[i][j])
                {
                    vector<pair<int, int>> st;
                    int cnt = 0;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();
                        if (seen[r][c] || grid[r][c] == 0)
                            continue;
                        seen[r][c] = 1;
                        st.push_back({r, c});
                        ++cnt;
                        for (auto &[dr, dc] : dirs)
                        {
                            int nr = r + dr, nc = c + dc;
                            if (!valid(nr, nc) || seen[nr][nc] || grid[nr][nc] == 0)
                                continue;
                            q.push({nr, nc});
                        }
                    }
                    for (auto &[r, c] : st)
                    {
                        sz[r][c] = cnt;
                        ids[r][c] = timer;
                    }
                    ++timer;
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            ret = max(ret, *max_element(sz[i].begin(), sz[i].end()));
        }

        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (grid[r][c] == 1)
                    continue;
                unordered_set<int> done;
                int cand = 0;
                for (auto &[dr, dc] : dirs)
                {
                    int nr = r + dr, nc = c + dc;
                    if (!valid(nr, nc) || done.find(ids[nr][nc]) != done.end())
                        continue;
                    done.insert(ids[nr][nc]);
                    cand += sz[nr][nc];
                }
                ret = max(cand + 1, ret);
            }
        }

        return ret;
    }
};
