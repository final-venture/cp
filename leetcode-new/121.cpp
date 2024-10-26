class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int maxx = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            res = max(res, maxx - prices[i]);
            maxx = max(maxx, prices[i]);
        }
        return res;
    }
};