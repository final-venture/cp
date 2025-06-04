class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size();
        vector<int> dp((1 << n), 1e8);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            int cnt = __builtin_popcount(mask);
            int fct = 1 + K * cnt;
            for (int bit = 0; bit < n; ++bit)
            {
                if (mask & (1 << bit)) continue;
                int newmask = (mask | (1 << bit));
                int tt = (strength[bit] + fct - 1) / fct;
                dp[newmask] = min(dp[newmask], dp[mask] + tt);
            }
        }
        return dp[(1 << n) - 1];
    }
};
