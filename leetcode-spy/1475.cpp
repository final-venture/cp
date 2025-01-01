class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ret(n);
        vector<int> x;
        for (int i = 0; i < n; ++i)
        {
            while (!x.empty() && prices[i] <= prices[x.back()])
            {
                int idx = x.back();
                ret[idx] = prices[idx] - prices[i];
                x.pop_back();
            }
            x.push_back(i);
        }
        while (!x.empty())
        {
            int idx = x.back();
            ret[idx] = prices[idx];
            x.pop_back();
        }
        return ret;
    }
};
