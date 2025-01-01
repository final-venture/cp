class Solution {
private:
    string s;
    int n;
    vector<int> freqs;
    vector<int> dp;
public:
    int makeStringGood(string s) {
        this -> s = s;
        int ret = 1e9;
        n = s.size();
        freqs.resize(27, 0);
        for (char c : s)
        {
            ++freqs[c - 'a'];
        }

        for (int x = 0; x <= n; ++x)
        {
            dp.resize(26);
            dp[25] = min(freqs[25], abs(x - freqs[25]));
            for (int i = 24; i >= 0; --i)
            {
                dp[i] = dp[i + 1] + min(freqs[i], abs(x - freqs[i]));
                int nxt = (i <= 23) ? dp[i + 2] : 0;

                if (freqs[i + 1] < x)
                {
                    int carry;
                    if (freqs[i] > x)
                    {
                        carry = freqs[i] - x;
                    }
                    else
                    {
                        carry = freqs[i];
                    }
                    dp[i] = min(dp[i], nxt + carry + max(0, x - (freqs[i + 1] + carry)));
                }
            }
            ret = min(ret, dp[0]);
            // cout << "considering " << x << ":" << '\n';
            // for (int i = 0; i <= 25; ++i) cout << dp[i] << ' ';
            // cout << '\n';
        }
        return ret;
    }
};
