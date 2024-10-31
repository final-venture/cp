// Memoisation
class Solution
{
private:
    vector<int> coins;
    vector<vector<int>> dp;

public:
    int coinChange(vector<int> &coins, int amount)
    {
        this->coins = coins;
        dp = vector<vector<int>>(coins.size() + 1, vector<int>(amount + 1, -1));
        int res = dfs(0, amount);
        return (res == INT_MAX - 1) ? -1 : res;
    }
    int dfs(int i, int amount)
    {
        if (amount < 0)
            return INT_MAX - 1;
        if (amount == 0)
            return 0;
        if (i >= coins.size())
            return INT_MAX - 1;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take = INT_MAX - 1;
        if (coins[i] <= amount)
            take = 1 + dfs(i, amount - coins[i]);
        int nottake = dfs(i + 1, amount);
        return dp[i][amount] = min(take, nottake);
    }
};

// DP
class Solution
{
private:
    vector<int> coins;
    vector<vector<int>> dp;

public:
    int coinChange(vector<int> &coins, int amount)
    {
        this->coins = coins;
        dp = vector<vector<int>>(coins.size() + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i < coins.size() + 1; ++i)
        {
            dp[i][0] = 0;
        }
        for (int j = 1; j < amount + 1; ++j)
        {
            dp[0][j] = INT_MAX - 1;
        }
        for (int i = 1; i < coins.size() + 1; ++i)
        {
            for (int j = 1; j < amount + 1; ++j)
            {
                int take = INT_MAX - 1;
                if (coins[i - 1] <= j)
                    take = 1 + dp[i][j - coins[i - 1]];
                int nottake = dp[i - 1][j];
                dp[i][j] = min(take, nottake);
            }
        }
        int res = dp[coins.size()][amount];
        return (res == INT_MAX - 1) ? -1 : res;
    }
};

// Space Optimisation
class Solution
{
private:
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> prev(amount + 1, INT_MAX - 1);
        vector<int> curr(amount + 1, 0);
        prev[0] = 0;

        for (int i = 1; i < coins.size() + 1; ++i)
        {
            for (int j = 1; j < amount + 1; ++j)
            {
                int take = INT_MAX - 1;
                if (coins[i - 1] <= j)
                    take = 1 + curr[j - coins[i - 1]];
                int nottake = prev[j];
                curr[j] = min(take, nottake);
            }
            prev = move(curr);
            curr = vector<int>(amount + 1, 0);
        }

        int res = prev[amount];
        return (res == INT_MAX - 1) ? -1 : res;
    }
};

// Fixed Size Arrays (memset + memcpy)
class Solution
{
private:
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int prev[amount + 1];
        memset(prev, 10001, sizeof(prev));
        int curr[amount + 1];
        memset(curr, 0, sizeof(curr));
        prev[0] = 0;

        for (int i = 1; i < coins.size() + 1; ++i)
        {
            for (int j = 1; j < amount + 1; ++j)
            {
                int take = 10001;
                if (coins[i - 1] <= j)
                    take = 1 + curr[j - coins[i - 1]];
                int nottake = prev[j];
                curr[j] = min(take, nottake);
            }
            memcpy(prev, curr, sizeof(curr));
            memset(curr, 0, sizeof(curr));
        }

        int res = prev[amount];
        return (res >= 10001) ? -1 : res;
    }
};
