class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        int n = arr.size();
        vector<unordered_set<int>> dp(n + 1);
        dp[0].insert(0);
        for (int i = 1; i <= n; ++i)
        {
            dp[i].insert(arr[i - 1]);
            for (int x : dp[i - 1])
            {
                dp[i].insert(x | arr[i - 1]);
            }
        }
        unordered_set<int> ret;
        for (int i = 1; i <= n; ++i)
        {
            for (int x : dp[i])
            {
                ret.insert(x);
            }
        }
        return static_cast<int>(ret.size());
    }
};
