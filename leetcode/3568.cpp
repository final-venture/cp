class Solution {
private:
    vector<pair<int, int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size();
        int cols = classroom[0].size();

        unordered_map<int, int> litter_to_bit;
        pair<int, int> start_pos;
        int litter_count = 0;

        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                if (classroom[i][j] == 'S') 
                {
                    start_pos = {i, j};
                } else if (classroom[i][j] == 'L') 
                {
                    litter_to_bit[i * cols + j] = litter_count++;
                }
            }
        }

        if (litter_count == 0) return 0;

        int all_litter_mask = (1 << litter_count) - 1;

        vector<vector<vector<vector<bool>>>> seen(
            rows, vector<vector<vector<bool>>>(
                cols, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << litter_count, false)
                )
            )
        );

        queue<tuple<int, int, int, int, int>> q;

        int start_r = start_pos.first, start_c = start_pos.second;
        seen[start_r][start_c][energy][0] = true;
        q.push({start_r, start_c, energy, 0, 0});

        while (!q.empty()) 
        {
            auto [r, c, e, mask, steps] = q.front();
            q.pop();

            if (mask == all_litter_mask) return steps;

            if (e == 0) continue;

            for (auto [dr, dc] : dirs) 
            {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && classroom[nr][nc] != 'X') 
                {
                    int next_energy = (classroom[nr][nc] == 'R') ? energy : e - 1;
                    int next_steps = steps + 1;

                    int new_mask = mask;
                    if (classroom[nr][nc] == 'L') 
                    {
                        new_mask |= (1 << litter_to_bit[nr * cols + nc]);
                    }

                    if (!seen[nr][nc][next_energy][new_mask]) 
                    {
                        seen[nr][nc][next_energy][new_mask] = next_steps;
                        q.push({nr, nc, next_energy, new_mask, next_steps});
                    }
                }
            }
        }
        
        return -1;
    }
};
