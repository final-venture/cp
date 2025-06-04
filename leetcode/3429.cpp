#define ll long long
class Solution
{
private:
    int n;
    vector<vector<int>> cost;
    ll dp[50005][3][3];

public:
    ll dfs(int idx, int prevl, int prevr)
    {
        if (idx > n / 2 - 1)
            return 0;
        if (prevl != -1 && dp[idx][prevl][prevr] != -1)
            return dp[idx][prevl][prevr];
        ll ret = 1e18;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i == j || i == prevl || j == prevr)
                    continue;
                ret = min(ret, cost[idx][i] + cost[n - idx - 1][j] + dfs(idx + 1, i, j));
            }
        }
        if (prevl != -1)
            return dp[idx][prevl][prevr] = ret;
        else
            return ret;
    }
    long long minCost(int n, vector<vector<int>> &cost)
    {
        this->cost = cost;
        this->n = n;
        memset(dp, -1, sizeof dp);
        return dfs(0, -1, -1);
    }
};
