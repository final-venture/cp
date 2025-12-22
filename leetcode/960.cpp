class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m);
        dp[m - 1] = 1;
        for (int i = m - 2; i >= 0; --i)
        {
            int cand = 1;
            for (int j = i + 1; j < m; ++j)
            {
                int ok = 1;
                for (auto &str : strs)
                {
                    if (str[i] > str[j])
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                {
                    cand = max(cand, dp[j] + 1);
                }
            }
            dp[i] = cand;
        }
        // for (auto x : dp) {
        //     cout << x << ' ';
        // }
        return m - *max_element(dp.begin(), dp.end());
    }
};
