#define ll long long
#define MOD 1000000007
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<vector<ll>> dp(2, vector<ll>(high + 1));
        dp[0][0] = 1;
        for (int j = 1; j < high + 1; ++j)
        {
            if (j - zero >= 0)
            {
                dp[0][j] += dp[0][j - zero];
                dp[0][j] += dp[1][j - zero];
                dp[0][j] %= MOD;
            }
            if (j - one >= 0)
            {
                dp[1][j] += dp[0][j - one];
                dp[1][j] += dp[1][j - one];
                dp[1][j] %= MOD;
            }
        }
        ll ret = 0;
        for (int i = low; i <= high; ++i)
        {
            ret += dp[0][i];
            ret += dp[1][i];
            ret %= MOD;
        }
        return ret;
    }
};
