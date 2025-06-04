class Solution
{
private:
    vector<int> prices;
    vector<vector<int>> dp;

public:
    int maxProfit(vector<int> &prices)
    {
        this->prices = prices;
        dp = vector<vector<int>>(2, vector<int>(prices.size() + 2, 0));

        for (int j = prices.size() - 1; j >= 0; --j)
        {
            for (int i = 1; i >= 0; --i)
            {
                if (i)
                {
                    int sell = prices[j] + dp[0][j + 2];
                    int dontsell = dp[1][j + 1];
                    dp[i][j] = max(sell, dontsell);
                }
                else
                {
                    int buy = -prices[j] + dp[1][j + 1];
                    int dontbuy = dp[0][j + 1];
                    dp[i][j] = max(buy, dontbuy);
                }
            }
        }

        return dp[0][0];
    }
};
