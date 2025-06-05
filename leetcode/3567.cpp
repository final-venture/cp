class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ret(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i < m - k + 1; ++i)
        {
            for (int j = 0; j < n - k + 1; ++j)
            {
                vector<int> nums;
                for (int i2 = i; i2 < i + k; ++i2)
                {
                    for (int j2 = j; j2 < j + k; ++j2)
                    {
                        nums.push_back(grid[i2][j2]);
                    }
                }
                sort(nums.begin(), nums.end());
                int nn = nums.size();
                int minn = 1e6;
                for (int i = 1; i < nn; ++i)
                {
                    if (nums[i] == nums[i - 1]) continue;
                    minn = min(minn, nums[i] - nums[i - 1]);
                }
                ret[i][j] = ((minn == 1e6) ? 0 : minn);
            }
        }
        return ret;
    }
};
