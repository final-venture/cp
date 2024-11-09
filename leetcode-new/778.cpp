class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, 1e5));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty())
        {
            int cost = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            if (r == rows - 1 && c == cols - 1)
                return dist[rows - 1][cols - 1];
            for (auto &[dr, dc] : dirs)
            {
                int nr = r + dr;
                int nc = c + dc;
                if (0 <= nr && nr < rows && 0 <= nc && nc < rows)
                {
                    int ncost = 0;
                    ncost = max(cost, grid[nr][nc]);
                    if (ncost < dist[nr][nc])
                    {
                        dist[nr][nc] = ncost;
                        pq.push({ncost, nr, nc});
                    }
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }
};
