#define MOD 1000000007
#define ll long long
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int k = words[0].size();
        int m = words.size();
        int n = target.size();
        vector<vector<int>> cnt(26, vector<int>(k, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                // cout << words[i][j] - 'a' << ' ';
                ++cnt[words[i][j] - 'a'][j];
            }
        }

        // for (int i = 0; i < 26; ++i)
        // {
        //     for (int j = 0; j < k; ++j)
        //     {
        //         cout << cnt[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        // dp[i][j] is ways when we're at target[i] and words[x][j].
        vector<vector<ll>> dp(n, vector<ll>(k, 0));
        // for (int i = 0; i < n; ++i)
        // {
        //     dp[i][0] = cnt[target[i] - 'a'][0];
        // }
        for (int j = 0; j < k; ++j)
        {
            dp[0][j] = cnt[target[0] - 'a'][j];
            if (j > 0) dp[0][j] += dp[0][j - 1];
            dp[0][j] %= MOD;
        }

        // cout << '\n';
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < k; ++j)
        //     {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < k; ++j)
            {
                dp[i][j] = cnt[target[i] - 'a'][j] * dp[i - 1][j - 1]; // take, take, TAKE
                dp[i][j] += dp[i][j - 1]; // and now we skip it
                dp[i][j] %= MOD;
            }
        }

        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < k; ++j)
        //     {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        return static_cast<int>(dp[n - 1][k - 1]);
    }
};
