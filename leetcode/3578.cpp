class Solution
{
public:
    int countPartitions(vector<int> &nums, int k)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> pfx(n + 1, 0);
        vector<int> dp(n);
        pfx[1] = 1;
        dp[0] = 1;
        set<pair<int, int>> win{{nums[0], 0}};
        int l = 0;
        for (int i = 1; i < n; ++i)
        {
            win.insert({nums[i], i});

            // if (nums[i] == 1) {
            //     cout << l << '\n';
            //     cout << win.rbegin()->first << ' ';
            //     cout << win.begin()->first << '\n';
            // }

            while (!win.empty() && (win.rbegin()->first - win.begin()->first) > k)
            {
                auto toRemove = win.find({nums[l], l});
                win.erase(toRemove);
                ++l;
            }

            dp[i] = pfx[i] + MOD - pfx[max(0, l - 1)];
            if (l - 1 < 0)
            {
                ++dp[i];
            }
            dp[i] %= MOD;
            pfx[i + 1] = pfx[i] + dp[i];
            pfx[i + 1] %= MOD;
        }
        // for (auto x : dp) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        // for (auto x : pfx) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        return dp[n - 1];
    }
};
