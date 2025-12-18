class Solution
{
public:
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
    {
        int n = prices.size();
        long long profit = 0;
        for (int i = 0; i < n; ++i)
        {
            profit += prices[i] * strategy[i];
        }
        long long ret = profit;
        int i = 0;
        for (; i < k / 2; ++i)
        {
            int delta = -(prices[i] * strategy[i]);
            profit += delta;
        }
        for (; i < k; ++i)
        {
            int delta = prices[i] - (prices[i] * strategy[i]);
            profit += delta;
        }
        ret = max(ret, profit);
        while (i < n)
        {
            int zero2orig = prices[i - k] * strategy[i - k];
            int one2zero = -prices[i - k / 2];
            int orig2one = prices[i] - (prices[i] * strategy[i]);
            profit += zero2orig;
            profit += one2zero;
            profit += orig2one;
            ret = max(ret, profit);
            ++i;
        }
        return ret;
    }
};
