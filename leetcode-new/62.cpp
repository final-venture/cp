class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 1);
        vector<int> curr(n, 0);

        for (int r = 1; r < m; ++r)
        {
            curr[0] = 1;
            for (int c = 1; c < n; ++c)
            {
                curr[c] = prev[c] + curr[c - 1];
            }
            prev = move(curr);
            curr = vector<int>(n, 0);
        }
        return prev[n - 1];
    }
};
