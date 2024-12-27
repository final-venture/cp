class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(2, vector<int>(n));
        dp[1][n - 1] = n - 1;
        dp[0][n - 1] = -1;
        // dp[0] is maxx of pair, dp[1] is max idx so far.
        for (int i = n - 2; i >= 0; --i)
        {
            dp[0][i] = max(dp[0][i + 1], values[i] + values[dp[1][i + 1]] + i - dp[1][i + 1]);
            dp[1][i] = (values[dp[1][i + 1]] + i - dp[1][i + 1] < values[i]) ? i : dp[1][i + 1];
        }
        return dp[0][0];
    }
};
