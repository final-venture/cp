#define ll long long
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> a;
        int l = 0; int r = 0; ll acu = 0;
        while (r < n)
        {
            acu += nums[r];
            if (r - l == k - 1)
            {
                a.push_back(acu);
                acu -= nums[l];
                ++l;
            }
            ++r;
        }
        int nn = a.size();

        // for (ll x : a) cout << x << ' ';
        // cout << '\n';

        vector<ll> dp(nn + 1);
        dp[0] = -1e15;
        for (int i = 1; i < nn + 1; ++i)
        {
            // cout << dp[i - 1] + a[i - 1] << ' ' << a[i - 1] << ' ' << dp[i - 1];
            // cout << '\n';
            if (i - k - 1 >= 0)
            {
                dp[i] = max(dp[i - k] + a[i - 1], a[i - 1]);
            }
            else
            {
                dp[i] = a[i - 1];
            }
        }
        ll maxx = LLONG_MIN;
        for (int i = 0; i < nn + 1; ++i)
        {
            maxx = max(maxx, dp[i]);
        }
        return maxx;
    }
};