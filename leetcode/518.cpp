class Solution
{
private:
    int amount;
    vector<int> coins;
    int dp[301][5001];

public:
    int change(int amount, vector<int> &coins)
    {
        this->coins = coins;
        this->amount = amount;
        memset(dp, -1, sizeof(dp));
        return dfs(0, amount);
    }

    int dfs(int i, int curramt)
    {
        if (curramt == 0)
            return 1;
        if (i >= coins.size())
            return 0;
        if (dp[i][curramt] != -1)
            return dp[i][curramt];
        int take = 0;
        if (curramt >= coins[i])
        {
            take = dfs(i, curramt - coins[i]);
        }
        int nottake = dfs(i + 1, curramt);
        return dp[i][curramt] = take + nottake;
    }
};
