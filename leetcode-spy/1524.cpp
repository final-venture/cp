class Solution {
    private:
        const int MOD = 1000000007;
    public:
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();
            vector<pair<int, int>> dp(n + 1); // odd, even
            dp[n] = {0, 0};
            for (int i = n - 1; i >= 0; --i)
            {
                if (arr[i] & 1)
                {
                    dp[i].first = dp[i + 1].second + 1;
                    dp[i].second = dp[i + 1].first;
                }
                else
                {
                    dp[i].first = dp[i + 1].first;
                    dp[i].second = dp[i + 1].second + 1;
                }
            }
            int ret = 0;
            for (auto& [odd, even] : dp)
            {
                ret += odd;
                ret %= MOD;
            }
            return ret;
        }
    };
    