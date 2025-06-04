class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<pair<int, int>> c2t {{costs[0], 1}, {costs[1], 7}, {costs[2], 30}};
        int maxx = *max_element(days.begin(), days.end());
        vector<int> dp(maxx + 1, -1);
        for (int x : days)
        {
            dp[x] = 1e9;
        }
        dp[0] = 0;
        for (int i = 1; i <= maxx; ++i)
        {
            for (auto& [c, t] : c2t)
            {
                if (dp[i] == -1) dp[i] = dp[i - 1];
                else
                {
                    dp[i] = min(dp[i], ((i - t >= 0) ? dp[i - t] : 0) + c);
                }
            }
        }
        // for (int x : dp) cout << x << ' ';
        return dp[maxx];
    }
};
